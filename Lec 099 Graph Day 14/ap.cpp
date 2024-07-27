#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

// Depth First Search (DFS) function to find articulation points in a graph
void dfs(int node, int parent, unordered_map<int, bool> &visited, vector<int> &low, vector<int> &disc,
         int &timer, vector<int> &ap, unordered_map<int, list<int>> &adj) {
    // Mark the current node as visited and initialize discovery time and low value
    visited[node] = true;
    low[node] = disc[node] = timer++;
    int child = 0;  // Counter to keep track of the number of children in the DFS tree

    // Traverse all adjacent nodes (neighbors) of the current node
    for (auto nbr : adj[node]) {
        if (parent == nbr) {
            // Skip the parent of the current node
            continue;
        }
        if (!visited[nbr]) {
            // If the neighbor is not visited, perform DFS on it
            dfs(nbr, node, visited, low, disc, timer, ap, adj);

            // Update the low value of the current node based on the child's low value
            low[node] = min(low[node], low[nbr]);

            // Check if the current node is an articulation point
            // Condition 1: If the low value of one of its children is greater than or equal to its discovery time
            if (low[nbr] >= disc[node] && parent != -1) {
                ap[node] = 1;  // Mark node as an articulation point
            }
            child++;  // Increment child count
        } else {
            // Update low value for the current node for back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Condition 2: If the node is root and has more than one child, it's an articulation point
    if (parent == -1 && child > 1) {
        ap[node] = 1;  // Mark node as an articulation point
    }
}

int main() {
    // Number of nodes and edges in the graph
    int n = 5;  // Number of nodes
    int e = 5;  // Number of edges

    // List of edges in the graph
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Adjacency list representation of the graph
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // Since it's an undirected graph, add edges both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize discovery and low values for each node
    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);

    // Track visited nodes
    unordered_map<int, bool> visited;

    // Track articulation points (ap[i] = 1 if node i is an articulation point)
    vector<int> ap(n, 0);
    int parent = -1;  // Initial parent value for the root

    // Initialize discovery and low values, and visited status for each node
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }

    // Call DFS for each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, parent, visited, low, disc, timer, ap, adj);
        }
    }

    // Output the articulation points found in the graph
    cout << "Articulation points in the graph are: ";
    for (int i = 0; i < n; i++) {
        if (ap[i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
