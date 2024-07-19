#include<iostream>
using namespace std;

int main(){
    char name[20];
    cin>>name;
    name[2]='\0';

    cout<<"Your name is "<<name;
    return 0;
}