#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template <typename T> //gives us power to decide datatype at time of writing code
class graph{
    public:

    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        //0 -> undirected
        //1 -> directed

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<< "->";
            for(auto j: i.second){
                cout<<j<<",";
            }

            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter no of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter number of edges : ";
    cin>>m;

    graph<int> g;
    
    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating a uidirected graph
        g.addEdge(u,v,0);

    }

    //printing
    g.printAdjList();

    return 0;
}