#include<bits/stdc++.h>
using namespace std;

//top down approach
int fib(int x,vector<int> &arr){ //recurssion
        //base case
        if(x<=1){
                return x;
        }

        if(arr[x]!= -1){ //handling overlapping case //dynamic programming
                return arr[x]; //memoziation
        }

        

        arr[x] = fib(x-1,arr)+fib(x-2,arr);
        return arr[x]; //time complexity = 0(n)
}
int main(){
        int n;
        cin>>n;

        vector<int> arr(n+1);
        for(int i=0;i<n+1;i++){
                arr[i] = -1;
        }

        cout<<fib(n,arr)<<endl;
        return 0;
}


//bottom ups approach

int fibi(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<n+1;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

//space optimiztion
int fibin(int n){
        int prev1 = 1;
        int prev2= 0;
        int curr = 0;

        if(n<=1){
            return n;
        }

        for(int i=2;i<=n;i++){
                curr = prev1+prev2;
                prev2 = prev1;
                prev1 = curr;
        }
        

        return curr;
}