//containing each number You are given an array of size
//between 1 and 'N' - 1 at least once. There is a single integer value that is present in the array twice.
//Your task is to find the duplicate integer value present in the array.

#include<iostream>
#include<vector>
using namespace std;
int finddupliacte(vector<int> arr){
  int ans=0;

  for(int i=0; i<arr.size(); i++){
    ans=ans^arr[i];
  }

  for(int i=0; i<arr.size(); i++){
    ans=ans^i;
  }

  return ans;
}
