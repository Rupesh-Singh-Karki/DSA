#include<iostream>
using namespace std;
int main(){
  int a;
  cout<<"Enter total money : ";
  cin>>a;

  int a100=0,a50=0,a20=0,a10=0,a1=0;

  switch(a){
    case 0: break;
    default: a100 = a/100;
             a %=100;
             a50=a/50;
             a %=50;
             a20=a/20;
             a %=20;
             a10=a/10;
             a %= 10;
             a1=a;
             break;   
  }

  cout<<"The number of 100 rupee notes = " << a100 <<endl;
  cout<<"The number of 50 rupee notes = "<< a50 <<endl;
  cout<<"The number of 20 rupee notes = "<< a20 <<endl;
  cout<<"The number of 10 rupee notes = "<< a10 <<endl;
  cout<<"The number of 1 rupee notes = "<< a1 <<endl;
  return 0;
}

