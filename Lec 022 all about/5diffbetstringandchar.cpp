#include<iostream>
using namespace std;
int main(){
    char name[20];
    string s="Rupesh";

    cin>>name;
    name[2]='\0';
    s[2]='\0';

    cout<<"STRING RESULT "<< s<<endl;
    cout<<"CHAR RESULT "<< name;

}