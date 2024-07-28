#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s) {
    // Mark the current node as visited
    visited[node] = true;

    // Visit all the neighbors of the current node
    for (auto nbr : adj[node]) {
        if (!visited[nbr]) {
            // Recursively perform DFS on the unvisited neighbor
            dfs(nbr, visited, adj, s);
        }
    }
    // After visiting all neighbors, push the current node to the stack
    s.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &trans) {
    // Mark the current node as visited
    visited[node] = true;

    // Visit all the neighbors of the current node in the transposed graph
    for (auto nbr : trans[node]) {
        if (!visited[nbr]) {
            // Recursively perform DFS on the unvisited neighbor
            revdfs(nbr, visited, trans);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // Step 1: Create an adjacency list for the graph
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the directed edge u -> v to the adjacency list
        adj[u].push_back(v);
    }

    // Step 2: Perform DFS to fill the stack with nodes in the order of their finishing times
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            // Perform DFS on unvisited nodes
            dfs(i, visited, adj, s);
        }
    }

    // Step 3: Create the transposed graph (reverse all edges)
    unordered_map<int, list<int>> trans;
    for (int i = 0; i < v; i++) {
        visited[i] = false;  // Reset visited map for the second pass
        for (auto nbr : adj[i]) {
            // Reverse the direction of each edge
            trans[nbr].push_back(i);
        }
    }

    // Step 4: Perform DFS on the transposed graph using the order of nodes in the stack
    int count = 0;  // To count the number of strongly connected components
    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!visited[top]) {
            // Increment the count for each new DFS call, which indicates a new strongly connected component
            count++;
            // Perform DFS on the transposed graph
            revdfs(top, visited, trans);
        }
    }

    return count;  // Return the number of strongly connected components
}
