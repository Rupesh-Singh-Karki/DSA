#include<iostream>
using namespace std;
int main(){
  int a=0;
  int b=1;

  int n;
  cout<<"Enter the place : ";
  cin>>n;
  
  for(int i=1; i<=(n-2); i++){
    int nn=a+b;
    a=b;
    b=nn;
  }
  cout<<b;
  
}