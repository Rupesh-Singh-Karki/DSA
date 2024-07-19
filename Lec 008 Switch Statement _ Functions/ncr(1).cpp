#include<iostream>
using namespace std;
int factorial(int n){
  int fact=1;
  for(int i=1; i<=n; i++){
    fact=fact*i;
  }
  return fact;
  
}
int ncr(int n, int r){
  int num=factorial(n);
  int den=factorial(r)*factorial(n-r);
  int ans=num/den;
  return ans;
}
int main(){
  int n,r;
  cin>> n >> r;
  int answer = ncr(n,r);
  cout<<answer;
  return 0;
}
