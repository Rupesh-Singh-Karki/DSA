#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<< i.first <<"->" ;
            for(auto j: i.second){
                cout<<"(" <<j.first<<","<< j.second<<")";
            }cout<<endl;
        }
    }

    void dfs(int node, stack<int> &s,unordered_map<int , bool> &visited ){
        visited[node] = true;      //topological sort

        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,s,visited);
            }
        }

        s.push(node);
    }

    void getshortestpath(int src, vector<int> &dist, stack<int> &s){
        dist[src] =0;

        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top]!=INT32_MAX){
                for(auto i:adj[top]){
                    if(dist[top]+i.second <dist[i.first]){
                        dist[i.first] = dist[top]+i.second;
                    }
                }
            }
        }
    }
};

int main(){

    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n = 6;
    unordered_map<int , bool> visited;
    stack<int> s;
    for(int i =0; i<n;i++){
        if(!visited[i]){
            g.dfs(i,s,visited);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT32_MAX;
    }

    g.getshortestpath(src,dist,s);

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    
    return 0;
}