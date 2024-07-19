#include <iostream>
using namespace std;

void selectionshort(vector<int>&arr, int n){
    for(int i=0; i<n; i++){
        int minindex=i;

        for(int j=i+1; j<n; j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);

    }
}