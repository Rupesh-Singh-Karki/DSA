#include<iostream>
using namespace std;
int givelength(char ch[]){
    int count = 0;
    for(int i=0; ch[i]!='\0'; i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cin>>name;
    //name[2]='\0';

    cout<<"Your name is "<<name<<endl;
    cout<<"Length is = "<<givelength(name);
    return 0;
}