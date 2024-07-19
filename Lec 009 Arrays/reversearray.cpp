#include<iostream>
using namespace std;
void reverse(int arr[], int n){
  int start=0;
  int end=n-1;
  while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }
}
void print(int arr[], int size){
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int array1[5]={1,5,0,-3,4};
  int array2[6]={1,7,0,3,4,5};
  
  reverse(array1, 5);
  reverse(array2, 6);

  print(array1, 5);
  print(array2, 6);

  return 0;
}