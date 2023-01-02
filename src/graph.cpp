#include "graph.h"
#include "haversine.h"

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
    nodes.insert({code, {airport, {}, false, vector<Airport>()}});
}

void Graph::unvisit() {
    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
        itr->second.visited = false;
    }
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

// Breadth-First Search: example implementation
/*void Graph::bfs(const string &code_airport) {
    unvisit();
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
            }
        }
    }
}*/

Airport Graph::getAirport(const string &code) const {
    return nodes.at(code).airport;
}

int Graph::numberOfFlights(const string &code) const {
    return nodes.at(code).adj.size();
}