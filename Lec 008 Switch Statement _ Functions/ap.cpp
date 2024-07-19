#include<iostream>
using namespace std;
int ap(int a,int n,int d){
  int ans=a+((n-1)*d);
  return ans;
}
int main(){
  int a,b,d;
  cout<<"Enter first two letters of your ap : ";
  cin>>a>>b;
  d=b-a;
  int n=1;
  cout<<"Type the number of digit you wanted to know ";
  cin>>n;
  int answer=ap(a,n,d);
  cout<<answer;
  return 0;


}