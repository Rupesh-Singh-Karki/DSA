#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

// Comparator function to sort edges based on their weights
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

// Function to initialize the parent and rank vectors for Disjoint Set Union (DSU)
void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is initially its own parent (root of itself)
        rank[i] = 0;   // Initial rank is set to 0
    }
}

// Function to find the representative or root of the set containing 'node'
// Uses path compression to make future queries faster
int findparent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node; // If the node is the root, return it
    }
    // Path compression: update parent of 'node' to its root
    return parent[node] = findparent(parent, parent[node]);
}

// Function to unite two sets represented by 'u' and 'v' using union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findparent(parent, u); // Find root of set containing 'u'
    v = findparent(parent, v); // Find root of set containing 'v'

    if (rank[u] < rank[v]) {
        parent[u] = v; // Attach the tree with smaller rank under the larger rank
    } else if (rank[u] > rank[v]) {
        parent[v] = u; // Attach the tree with smaller rank under the larger rank
    } else {
        parent[v] = u; // If ranks are the same, attach 'v' under 'u'
        rank[u]++;     // Increase the rank of 'u'
    }
}

// Function to compute the minimum spanning tree using Kruskal's algorithm
int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    // Sort the edges by weight in non-decreasing order
    sort(edges.begin(), edges.end(), cmp);

    // Initialize parent and rank vectors for DSU
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int minweight = 0; // To store the total weight of the MST

    // Iterate through each edge in sorted order
    for (int i = 0; i < edges.size(); i++) {
        int u = findparent(parent, edges[i][0]); // Find root of the first vertex
        int v = findparent(parent, edges[i][1]); // Find root of the second vertex
        int wt = edges[i][2];                    // Get the weight of the edge

        // If 'u' and 'v' are in different sets, include this edge in the MST
        if (v != u) {
            minweight += wt;               // Add edge weight to the MST total
            unionSet(u, v, parent, rank);  // Unite the sets of 'u' and 'v'
        }
    }

    return minweight; // Return the total weight of the MST
}
