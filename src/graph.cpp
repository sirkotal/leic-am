#include "graph.h"
#include "haversine.h"

#define MAX std::numeric_limits<double>::max()

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(bool dir) {
    this->hasDir = dir;
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(const string& source, const string& target, const string& airline) {
    auto src_airport = nodes.find(source);
    auto tar_airport = nodes.find(target);

    if (src_airport == nodes.end() || tar_airport == nodes.end() || src_airport == tar_airport) {
        return;
    }

    double distance = haversine(src_airport->second.airport, tar_airport->second.airport);

    src_airport->second.adj.push_back({target, airline, distance});

    if(!this->hasDir)
        tar_airport->second.adj.push_back({ source, airline, distance});
}

void Graph::addNode(const string &code, const Airport &airport) {
    nodes.insert({code, {airport, {}, false, list<vector<pair<Airport, string>>>(), MAX}});
}

void Graph::addMarkedAirline(const string &airline) {
    marked_airlines.insert(airline);
}

void Graph::removeMarkedAirline(const string &airline) {
    if (marked_airlines.find(airline) == marked_airlines.end())
        return;

    marked_airlines.erase(airline);
}

void Graph::clearMarkedAirlines() {
    marked_airlines.clear();
}

unordered_set<string> Graph::getMarkedAirlines() {
    return marked_airlines;
}

bool Graph::checkAirport(const string &airport) {
    return nodes.find(airport) != nodes.end();
}

void Graph::unvisit() {
    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        itr->second.visited = false;
        itr->second.fromSRC.clear();
    }
}

struct PriorityCompare {
    bool operator() (pair<string, double> const &p1, pair<string, double> const &p2){
        return p1.second > p2.second;
    }
};

void Graph::shortPath(const string &code_airport) {
    unvisit();

    priority_queue<pair<string, double>, vector<pair<string, double>>, PriorityCompare> q;
    nodes[code_airport].distanceSRC = 0;
    nodes[code_airport].fromSRC.push_back({{nodes[code_airport].airport,""}});


    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        if (itr->first == code_airport) {
            q.push({itr->first, itr->second.distanceSRC});
        }
        else {
            itr->second.distanceSRC = MAX;
        }
    }

    while (!q.empty()) {
        pair<string, double> p = q.top();
        q.pop();

        Node& n1 = nodes[p.first];
        for (auto &e: n1.adj) {
            if (marked_airlines.find(e.airline) == marked_airlines.end() && !marked_airlines.empty()) {
                continue;
            }
            Node& v = nodes[e.dest];
            double val = e.distance + n1.distanceSRC;

            if (val < v.distanceSRC) {
                v.fromSRC.clear();

                for (auto path: n1.fromSRC) {
                    path.push_back({v.airport, e.airline});
                    v.fromSRC.push_back(path);
                }
                v.distanceSRC = val;
                q.push({e.dest, val});
            }
            else if (val == v.distanceSRC && val < MAX) {
                for (auto path : n1.fromSRC) {
                    path.push_back({v.airport,e.airline});
                    v.fromSRC.push_back(path);
                }
            }
        }
    }
}

double Graph::getShortestPath(const string &source, const string &target) {
    shortPath(source);
    return nodes[target].distanceSRC;
}

// Depth-First Search: implementation
void Graph::dfs(const string &code_airport) {
    nodes[code_airport].visited = true;

    for (auto itr = nodes[code_airport].adj.begin(); itr != nodes[code_airport].adj.end(); itr++) {
        Node& target = nodes[itr->dest];

        if (target.visited == false) {
            dfs(itr->dest);
        }
    }
}

// Breadth-First Search: implementation
void Graph::bfs(const string &code_airport) {
    queue<string> q; // queue of unvisited nodes
    q.push(code_airport);
    unvisit();

    nodes[code_airport].visited = true;
    nodes[code_airport].fromSRC.push_back({{nodes[code_airport].airport, "" }});

    while (!q.empty()) { // while there are still unvisited nodes
        string u = q.front();
        q.pop();
        Node& node = nodes[u];

        // show node order
        for (auto& e : node.adj) {
            if (marked_airlines.find(e.airline) == marked_airlines.end() && !marked_airlines.empty()) {
                continue;
            }
            string w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                for (auto omega: node.fromSRC) { // Airports already in the vector
                    omega.push_back({nodes[w].airport, e.airline});
                    nodes[w].fromSRC.push_back(omega);
                }
            }
        }
    }
}

list<vector<pair<Airport, string>>> Graph::getAirportsTraveled(const string &source, const string &target) {
    bfs(source);
    return nodes[target].fromSRC;
}

Airport Graph::getAirport(const string &code) const {
    return nodes.at(code).airport;
}

int Graph::numberOfFlights(const string &code) const {
    return nodes.at(code).adj.size();
}

int Graph::numAirlinesFromAirport(const string &airport) {
    set<string> airlines;

    for (const auto &e: nodes[airport].adj) {
        airlines.insert(e.airline);
    }

    return airlines.size();
}

unsigned int Graph::minFlights(const string &source, const string &target) {
    bfs(source);
    return nodes[target].fromSRC.front().size() - 1;
}

string Graph::findAirport(const double &lat, const double &lon) {
    string air_code;
    double l1 = MAX;
    double l2 = MAX;
    for (const auto &n: nodes) {
        if (haversine(lat, lon, n.second.airport.getLatitude(), n.second.airport.getLongitude()) <
        haversine(lat, lon, l1, l2)) {
            air_code = n.second.airport.getAirCode();
            l1 = n.second.airport.getLatitude();
            l2 = n.second.airport.getLongitude();
        }
    }
    return air_code;
}

vector<string> Graph::findAirportByCity(const string &city) {
    vector<string> city_airports;
    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        if (itr->second.airport.getCity() == city) {
            city_airports.push_back(itr->first);
        }
    }

    return city_airports;
}

map<double,string> Graph::findAirportsInRadius(double latitude, double longitude, int radius) {
    map<double,string> airports;
    for (const auto &node: nodes) {
        double dist = haversine(node.second.airport.getLatitude(),node.second.airport.getLongitude(), latitude,longitude);
        if (dist < radius) {
            airports.emplace(dist, node.first);
        }
    }
    return airports;
}

set<string> Graph::getCitiesReached(const string &airport, const int &num) {
    set<string> cities;
    bfs(airport);

    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        Node &n = itr->second;

        if (n.airport.getAirCode() == airport) {
            continue;
        }

        if (n.fromSRC.size() - 1 <= num) {
            cities.insert(n.airport.getCity());
        }
    }

    return cities;
}

deque<Airport> Graph::getAirportsReached(const string &airport, const int &num) {
    bfs(airport);

    deque<Airport> airports;

    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        Node &n = itr->second;

        if (n.airport.getAirCode() == airport) {
            continue;
        }

        if (n.fromSRC.size() - 1 <= num) {
            airports.push_back(n.airport);
        }
    }

    return airports;
}

set<string> Graph::getCountriesReached(const string &airport, const int &num) {
    set<std::string> countries;
    bfs(airport);

    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        Node &n = itr->second;
        if (n.airport.getAirCode() == airport) {
            continue;
        }

        if (n.fromSRC.size() - 1 <= num) {
            countries.insert(n.airport.getCountry());
        }
    }

    return countries;
}
