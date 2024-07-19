#include<iostream>
using namespace std;
int oddeven(){
  int a;
  cin>>a;
  if(a%2==0){
    cout<<"Even Number";
  }
  else{
    cout<<"Odd Number";
  }
  return 0;
}
int main(){
  int ans=oddeven();
  return 0;
}