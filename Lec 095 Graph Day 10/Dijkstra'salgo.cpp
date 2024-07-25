#include <bits/stdc++.h> 
#include <unordered_map>
#include <set>
#include <list>
using namespace std;

// Function to perform Dijkstra's algorithm to find the shortest path from the source node
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create an adjacency list to store the graph
    unordered_map<int, list<pair<int, int>>> adj;
    
    // Populate the adjacency list with the provided edges
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];  // Starting vertex of edge
        int v = vec[i][1];  // Ending vertex of edge
        int w = vec[i][2];  // Weight of edge

        // Since this is an undirected graph, add edges in both directions
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize the distance vector with maximum integer values (infinity)
    vector<int> dist(vertices, INT32_MAX);

    // Set to act as a priority queue, storing pairs of (distance, node)
    set<pair<int, int>> st;

    // Distance to the source node from itself is always 0
    dist[source] = 0;
    
    // Insert the source node into the set with distance 0
    st.insert(make_pair(0, source));

    // Main loop to process each node in the priority queue
    while(!st.empty()) {
        // Extract the node with the smallest distance from the set
        auto top = *(st.begin());
        int nodedistance = top.first;
        int topnode = top.second;

        // Remove the processed node from the set
        st.erase(st.begin());

        // Explore all the neighbors of the current node
        for(auto neighbour: adj[topnode]) {
            int neighborNode = neighbour.first;
            int edgeWeight = neighbour.second;

            // Calculate the potential new distance to the neighbor
            if(nodedistance + edgeWeight < dist[neighborNode]) {
                // Check if the current neighbor node is already in the set
                auto record = st.find(make_pair(dist[neighborNode], neighborNode));
                if(record != st.end()) {
                    // If found, remove the outdated record of this neighbor
                    st.erase(record);
                }

                // Update the shortest distance for the neighbor node
                dist[neighborNode] = nodedistance + edgeWeight;
                // Insert the updated distance and node into the set
                st.insert(make_pair(dist[neighborNode], neighborNode));
            }
        }
    }

    // Return the vector of shortest distances from the source node
    return dist;
}
