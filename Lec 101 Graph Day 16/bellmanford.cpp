#include <iostream>
#include <vector>
using namespace std;

/**
 * Implements the Bellman-Ford algorithm to find the shortest paths from a single source vertex
 * to all other vertices in a weighted graph. This algorithm can handle graphs with negative weight edges.
 * 
 * @param V     Number of vertices in the graph.
 * @param edges List of edges, where each edge is represented as a vector of three integers {u, v, wt}
 *              indicating an edge from vertex u to vertex v with weight wt.
 * @param S     Source vertex from which shortest paths are calculated.
 * 
 * @return      A vector containing the shortest distances from the source to each vertex.
 *              If a negative weight cycle is detected, returns {-1}.
 */
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Step 1: Initialize the distance to all vertices as infinity (a large number), except the source
    vector<int> dist(V, 1e8);
    dist[S] = 0;  // Distance from the source to itself is always 0

    // Step 2: Relax all edges (V-1) times to find the shortest paths
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];  // Starting vertex of the edge
            int v = it[1];  // Ending vertex of the edge
            int wt = it[2]; // Weight of the edge

            // If the distance to u is not infinity and u + wt is less than the current distance to v
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;  // Update the distance to v
            }
        }
    }

    // Step 3: Perform one more relaxation to check for negative-weight cycles
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        // If a further relaxation is possible, a negative cycle exists
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};  // Return {-1} to indicate a negative-weight cycle
        }
    }

    // Return the array of shortest distances from the source
    return dist;
}

int main() {
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    // Example edges: {u, v, wt}
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    // Calculate shortest paths
    vector<int> result = bellman_ford(V, edges, S);

    // Display the results
    if (result.size() == 1 && result[0] == -1) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Shortest distances from source vertex " << S << " to all other vertices:" << endl;
        for (int i = 0; i < result.size(); ++i) {
            cout << "Vertex " << i << ": ";
            if (result[i] == 1e8) {
                cout << "Infinity" << endl; // If distance is still infinity, the vertex is unreachable
            } else {
                cout << result[i] << endl;
            }
        }
    }

    return 0;
}
