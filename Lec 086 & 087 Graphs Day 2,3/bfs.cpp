#include<unordered_map>
#include<queue>
#include<iostream>
using namespace std;
void bfs(vector<vector<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans, int node ){
    queue<int> q;
    q.push(node);
    visited[node] =1;

    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        //stor frontnode in ans
        ans.push_back(frontnode);

        //traverse through all neigbhours
        for(auto i: adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int,bool> visited;

    //traverse all component of a graph
    bfs(adj,visited,ans,0);

    return ans;

}