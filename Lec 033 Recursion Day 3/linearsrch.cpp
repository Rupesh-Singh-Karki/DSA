#include<iostream>
using namespace std;

bool ls(int arr[], int n, int k){
    //base case
    if(n==0){
        return false;
    }

    if(arr[0]==k){
        return true;
    }
    else{
        bool ans=ls(arr+1,n-1,k);
        return ans;
    }



}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=3;
    bool ans=ls(arr,5,key);
    if(ans){
        cout<<"present";
    }
    else{
        cout<<"not present";
    }

    return 0;
}