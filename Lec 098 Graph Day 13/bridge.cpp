#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// Depth First Search to find bridges in a graph
void dfs(int node, int parent, unordered_map<int, bool> &visited, vector<int> &low, vector<int> &disc,
         int timer, vector<vector<int>> &result, unordered_map<int, list<int>> &adj) {
    // Mark the current node as visited
    visited[node] = true;
    // Initialize discovery time and low value
    low[node] = disc[node] = timer++;

    // Explore all the neighbors of the current node
    for (auto nbr : adj[node]) {
        if (parent == nbr) {
            // If the neighbor is the parent, continue to the next neighbor
            continue;
        }
        if (!visited[nbr]) {
            // If the neighbor is not visited, recursively call dfs for the neighbor
            dfs(nbr, node, visited, low, disc, timer, result, adj);

            // After returning from the recursion, update the low value of the current node.
            //maybe the child node has back edge so we might have a new low[node] value
            low[node] = min(low[node], low[nbr]);

            // Check if the edge is a bridge
            if (low[nbr] > disc[node]) {
                // If the condition is true, it means that the edge from node to nbr is a bridge
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        } else {
            // If the neighbor is already visited, update the low value of the current node
            // This is a back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Function to find all the bridges in a graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Adjacency list to store the graph
    unordered_map<int, list<int>> adj;
    // Populate the adjacency list with the given edges
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Timer to keep track of discovery times
    int timer = 0;
    // Vectors to store discovery and low values
    vector<int> disc(v);
    vector<int> low(v);
    // Map to keep track of visited nodes
    unordered_map<int, bool> visited;
    int parent = -1;

    // Initialize discovery and low values, and mark all nodes as unvisited
    for (int i = 0; i < v; i++) {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }

    // Result vector to store all bridges
    vector<vector<int>> result;

    // Iterate over all vertices and apply DFS if the vertex is not visited
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, parent, visited, low, disc, timer, result, adj);
        }
    }

    // Return the list of bridges
    return result;
}
