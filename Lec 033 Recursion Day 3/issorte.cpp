#include<iostream>
using namespace std;

bool issorted(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans=issorted(arr+1,n-1); //shifts the pointer to the first index
        return ans;
    }

    

}


int main(){
    int arr[5]={1,2,3,4,5};
    int ans=issorted(arr,5);

    if(ans){
        cout<<"The array is sorted ";
    }
    else{
        cout<<"Not sorted ";
    }
}