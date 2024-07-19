#include<iostream>
using namespace std;

bool binarysearch(int *arr, int s, int e, int k){
    //base case
    if(s>e){
        return 0;
    }
    int mid=s + (e-s)/2;

    if(arr[mid]==k){
        return 1;
    }

    if(arr[mid]<k){
        return binarysearch(arr,mid+1,e,k);
    }
    else{
        return binarysearch(arr,s,mid-1,k);
    }

}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=4;
    cout<<binarysearch(arr,0,4,key);
    
    
}