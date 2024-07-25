#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>
#include<iostream>

using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0; i<e; i++){
      int u = edges[i][0];
      int v= edges[i][1];

      adj[u].push_back(v);
    }

    vector<int> indegre(v);

    for(auto i: adj){
        for(auto j: i.second){
            indegre[j]++;
        }
    }

    queue<int> q;

    for(int i=0; i<v;i++){
        if(indegre[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front]){
            indegre[neighbour]--;
            if(indegre[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    return ans;


}