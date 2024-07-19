#include<iostream>
using namespace std;

int fib(int n) {
    //base case
    if(n==0 || n==1){
        return n;
    }

    return fib(n-1)+fib(n-2); //f(n)=f(n-1)+f(n+1);
}

int main(){
    int n;
    cin>>n;
    
    cout<<fib(n)<<endl;


}