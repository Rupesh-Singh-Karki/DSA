#include<iostream>
using namespace std;
int getmax(int array[], int size){
  int maxi=INT32_MIN;                //min isliye use kiya kyuki koi bhi value ise badi hogi use store kara lenge
  for(int i=0; i<size; i++){            //phir use agli value sai compare karwa lenge.
    if(array[i]>maxi){           //we can also use
      maxi=array[i];             // maxi=max(maxi, array[i]) instead of if condition.
    }
  }
  return maxi;
}
int getmin(int array[], int size){
  int mini=INT32_MAX;
  for(int i=0; i<size; i++){
    if(array[i]<mini){            //simply use min function already exists
      mini=array[i];             // maxi=min(maxi, array[i]) instead of if condition.
    }
  }
  return mini;
}
int main(){
  int size;
  cin>>size;
  int arr[100];
  for(int i=0; i<size; i++ ){
    cin>>arr[i];
  }
  cout<<"The maximum value of the array is = "<<getmax(arr,size)<<endl;
  cout<<"The minimum value of the array is = "<<getmin(arr,size)<<endl;
  return 0;
}