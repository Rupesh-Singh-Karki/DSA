#include<iostream>
using namespace std;
int main(){

  int a;
  int b=2;
  cout<<"Input no : ";
  cin>>a;

  while(b<a){
    if(a%b==0){
      cout<<"The no is not prime";
      return 0;
    }
    else{
      b=b+1;
    }
  }

  if(a==b){
    cout<<"The no is defenitely prime";
  }

  return 0;
}