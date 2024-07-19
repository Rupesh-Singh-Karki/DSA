#include<iostream>
using namespace std;
bool iseven(int a){
  if(a&1){
    return 0;
  }
  return 1;
}
int main(){
  int a;
  cin>>a;
  if(iseven(a)){
    cout<<"The number is even ";
  }
  else{
    cout<<"The number is odd";
  }
  return 0;
}