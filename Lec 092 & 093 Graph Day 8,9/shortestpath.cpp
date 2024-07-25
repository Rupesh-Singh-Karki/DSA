#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v= edges[i].second;

      adj[u].push_back(v);
	  adj[v].push_back(u);
    }

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;

	visited[s]=true;
	parent[s]=-1;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neighbour: adj[front]){
			if(!visited[neighbour]){
				visited[neighbour]=1;
				q.push(neighbour);
				parent[neighbour]=front;
			}
		}
	}

	vector<int> ans;
	int crntnode = t;
	ans.push_back(crntnode);

	while(crntnode != s){
		crntnode = parent[crntnode];
		ans.push_back(crntnode);
	}

	reverse(ans.begin(), ans.end());
	return ans;

}
