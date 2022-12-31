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

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
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
}