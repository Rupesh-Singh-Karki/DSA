#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <limits.h>
#include<iostream>

using namespace std;
/*
MST - MINIMUM SPANNIG TREE
A tree madefrom a graph using minimum weighted edges also it should have n nodes and (n-1) edges.
If this condition is fulfiled then it can be teremed as a mst
*/

// Function to calculate the Minimum Spanning Tree (MST) using Prim's algorithm
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

    // Adjacency list to store the graph. Each vertex points to a list of its adjacent vertices with edge weights.
    unordered_map<int, list<pair<int, int>>> adj;

    // Populate the adjacency list with the graph data
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;  // Vertex u of the edge
        int v = g[i].first.second; // Vertex v of the edge
        int w = g[i].second;       // Weight of the edge

        // Since the graph is undirected, add edges both ways
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Vectors to store key values, MST set status, and parent nodes
    vector<int> key(n + 1);     // Minimum weights to connect each node to the MST
    vector<bool> mst(n + 1);    // MST inclusion status of each node
    vector<int> parent(n + 1);  // Parent nodes in the MST

    // Initialize the vectors
    for (int i = 0; i <= n; i++) {
        key[i] = INT32_MAX; // Initialize all keys to a large number
        mst[i] = false;     // Initially, no vertices are included in the MST
        parent[i] = -1;     // Parent of each node is set to -1 initially
    }

    // Start from the first vertex by setting its key value to 0
    key[1] = 0;  // Ensure that the MST includes the first vertex
    parent[1] = -1;  // The first vertex is the root of the MST, so it has no parent

    // Iterate to construct the MST with n-1 edges (since MST has n-1 edges for n vertices)
    for (int i = 1; i < n; i++) {
        int mini = INT32_MAX;  // Variable to find the minimum key value
        int u;  // Vertex with the minimum key value

        // Find the vertex u not in the MST with the minimum key value
        for (int j = 1; j <= n; j++) {
            if (!mst[j] && key[j] < mini) {
                u = j;
                mini = key[j]; //can be eliminated using min heap
            }
        }

        // Include vertex u in the MST
        mst[u] = true;

        // Update the key values and parent index of the adjacent vertices of u
        for (auto it : adj[u]) {
            int v = it.first;  // Adjacent vertex of u
            int w = it.second; // Weight of the edge from u to v

            // If v is not in the MST and the edge weight is smaller than the current key value
            if (!mst[v] && w < key[v]) {
                parent[v] = u;  // Update parent of v to u
                key[v] = w;     // Update key value of v
            }
        }
    }

    // Vector to store the result of the MST
    vector<pair<pair<int, int>, int>> ans;

    // Store the MST edges in the result vector
    for (int i = 2; i <= n; i++) { //The starting vertex has no parent in the context of an MST because it is the root of the tree
        ans.push_back({{parent[i], i}, key[i]});
    }

    // Return the list of edges in the MST with their respective weights
    return ans;
}
