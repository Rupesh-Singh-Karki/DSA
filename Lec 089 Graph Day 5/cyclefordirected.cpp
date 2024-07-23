#include<unordered_map>
#include<list>
#include<iostream>
#include<vector>
using namespace std;
bool iscyclic(int node, unordered_map<int,list<int>> adj,unordered_map<int, bool> &visited ,unordered_map<int, bool> &dfsvisited){
  visited[node] = true;
  dfsvisited[node] = true;

  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
      bool check = iscyclic(neighbour, adj, visited, dfsvisited);
      if(check){
        return true;
      }
    }
    else if(dfsvisited[neighbour]){
      return true;
    }
  }

  visited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v= edges[i].second;

      adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for(int i=0; i<n; i++){ 
      if(!visited[i]){
        bool ans = iscyclic(i,adj,visited,dfsvisited);
        if(ans == true){
          return true;
        }
      }
    }

    return false;
} 

///////////////////////////////////////////////////////////////////////
//THIS ONE DOES NOT SHOW TLE
bool isCyclicUtil(int node, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, unordered_map<int, bool>& inRecStack) {
    // Mark the current node as visited and part of recursion stack
    visited[node] = true;
    inRecStack[node] = true;

    // Recur for all vertices adjacent to this vertex
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicUtil(neighbour, adj, visited, inRecStack)) {
                return true;
            }
        } else if (inRecStack[neighbour]) {
            // If the neighbour is in the recursion stack, there is a cycle
            return true;
        }
    }

    // Remove the vertex from recursion stack
    inRecStack[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v= edges[i].second;

      adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> inRecStack;

    // Initialize visited and inRecStack for all nodes
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        inRecStack[i] = false;
    }

    // Check for cycles in each component
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (isCyclicUtil(i, adj, visited, inRecStack)) {
                return true;
            }
        }
    }

    return false;
}