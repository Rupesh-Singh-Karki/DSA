//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
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
            path.pop_back();
        }
        
        //left
        newx=x;
        newy=y-1;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'L');
            path.pop_back();
        }
        
        //right
        newx=x;
        newy=y+1;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'R');
            path.pop_back();
        }
        
        
        //Up
        newx=x-1;
        newy=y;
        if(issafe(newx, newy,visited,m,n)){
            solve(m,n,ans,newx,newy,visited,path+'U');
            path.pop_back();
        }
        
        visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        //error case
        if(m[0][0]==0){
            return ans;
        }
        int srcx=0;
        int srcy=0;
        
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path="";
        solve(m,n,ans,srcx,srcy,visited,path);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends