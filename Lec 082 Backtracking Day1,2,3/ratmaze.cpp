#include<iostream> 
#include<vector>
using namespace std;
bool issafe(int x,int y,vector<vector<bool>> visited, vector<vector<int>> &m, int n){
        if((x>=0 && x<n ) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve( vector<vector<int>> &m, int n,vector<string>& ans, int x, int y,vector<vector<bool>> visited,string path){
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
            
        }
        
        visited[x][y]=1;
        
        //down
        int newx=x+1;
        int newy=y;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'D');
        }
        
        //left
        newx=x;
        newy=y-1;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'L');
        }
        
        //right
        newx=x;
        newy=y+1;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'R');
        }
        
        
        //Up
        newx=x-1;
        newy=y;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'U');
        }
        
        visited[x][y]=0;
    }
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
        //error case
        if(arr[0][0]==0){
            return ans;
        }
        int srcx=0;
        int srcy=0;
        
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path="";
        solve(arr,n,ans,srcx,srcy,visited,path);
        return ans;
}