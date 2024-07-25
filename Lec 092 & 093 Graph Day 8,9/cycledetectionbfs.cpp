#include<unordered_map>
#include<list>
#include<queue>
#include<iostream>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first-1; //because graph started from 1 and we made it from 0
      int v= edges[i].second-1;//or instead in line 26 just start i from 1;

      adj[u].push_back(v);
    }

    vector<int> indegre(n);

    for(auto i: adj){
        for(auto j: i.second){
            indegre[j]++;
        }
    }

    queue<int> q;

    for(int i=0; i<n;i++){
        if(indegre[i]==0){
            q.push(i);
        }
    }

    int cnt =0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;

        for(auto neighbour: adj[front]){
            indegre[neighbour]--;
            if(indegre[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    if(cnt == n){
        return false;
    }
    else{
        return true;
    }
}