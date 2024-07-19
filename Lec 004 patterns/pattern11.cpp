#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    for (int s = n-1; s>=i; s--)
    {
      cout<<" ";
    }
    for (int j = 1; j<=i ; j++)
    {
      cout<<j;
    }
    for (int st = i-1; st>0; st--)
    {
      cout<<st;
    }
    cout<<endl;
    
  }

  return 0;
}
