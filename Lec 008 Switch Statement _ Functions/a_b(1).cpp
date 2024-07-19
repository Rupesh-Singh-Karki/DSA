#include <iostream>
using namespace std;

int main() {
    int sum=0;
    int a,b;
    cin>>a>>b;
    while(a!=0){
        if(a&1){
            sum++;
        }
        a=a>>1;
    }
    while(b!=0){
        if(b&1){
            sum++;
        }
        b=b>>1;
    }
    cout<<sum;
    return 0;
}