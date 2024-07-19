#include<iostream>
using namespace std;
int main(){
  int a,b;
  cout<<"Enter the first number = ";
  cin>>a;

  cout<<"Enter the 2nd number = ";
  cin>>b;

  char ch;
  cout<<"Enter the operation = ";
  cin>>ch;

  switch(ch){
    case '+':cout<<"The answer for the question is = "<<a+b;
            break;
    case '-':cout<<"The answer for the question is = "<<a-b;
             break;    
    case '*':cout<<"The answer for the question is = "<<a*b;
             break;
    case '/':cout<<"The answer for the question is = "<<a/b;
             break;
    case '%':cout<<"The answer for the question is = "<<a%b;
             break;
    default:cout<<"Enter a Valid Operation";
            break; 
            
  }
  return 0;
}