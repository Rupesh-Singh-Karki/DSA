#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int i=1;
  
  while(i<=n){
    int s=1;
    int j=1;
    while(s<=n-i){
      cout<<" ";
      s++;
    }
    
    while(j<=i){
      cout<<"*";
      j++;
    }
    int k=1;
    while(k<=i-1){
      cout<<"*";
      k++;
    } 
    cout<<endl;
    i++;

  }
  



  return 0;
}