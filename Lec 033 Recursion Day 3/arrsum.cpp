#include<iostream>
using namespace std;

int sun(int arr[], int n){
    //base case
    if(n==1){
        return arr[0];
    }
    if(n==0){
        return 0;
    }

    int remainingPart = sun(arr+1, n-1);
    int sum = arr[0] + remainingPart;

    return sum;

}

int main(){
    int arr[5]={1,2,3,4,5};
    int sum=sun(arr,5);
    cout<<sum;
    return 0;
}