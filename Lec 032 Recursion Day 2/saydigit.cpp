#include<iostream>
using namespace std;
void saydigit(int n){
    if(n==0){
        return ;
    }
    string arr[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    int k=n%10;
    n=n/10;
    


    saydigit(n);
    cout<<arr[k]<<" "; //head recursion eg 234 to cout pehle 2 then 3 then 4 hoga jabki pehle humpar 4 araha hai

    return ;


}

int main(){
    int n;
    cin>>n;
    
    saydigit(n);


}