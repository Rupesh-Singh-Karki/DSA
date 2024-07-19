#include <iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int count=0;
    int pivot=arr[s];
    for(int i=s+1; i<=e;i++){
        if(pivot>=arr[i]){
            count++;
        }
    }
    int p=count+s;

    swap(arr[p],arr[s]);
    int i=s;
    int j=e;
    while(i<p && j>p){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<p && j>p){
            swap(arr[i++],arr[j--]);
        }

    }

    return p;



}
void qs(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }

    int p= partition(arr,s,e);

    //taking care of left part
    qs(arr,s,p-1);

    //right side
    qs(arr,p+1,e);



}

int main(){
    int arr[10]={4,6,8,14,9,3,6,18,1,13};
    int n=10;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;

    qs(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}