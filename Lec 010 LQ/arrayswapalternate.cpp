#include<iostream>
using namespace std;
void altswap(int arr[], int size){
  for(int i=0; i<size; i+=2){
    if(i+1<size){
      swap(arr[i],arr[i+1]);
    }
  }
}
void print(int arr[],int size){
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int array[8]={1,2,3,4,5,6,7,8};
  int array2[7]={1,2,3,4,5,6,7};
  altswap(array,8);
  altswap(array2,7);

  print(array,8);
  print(array2,7);

  return 0;
}