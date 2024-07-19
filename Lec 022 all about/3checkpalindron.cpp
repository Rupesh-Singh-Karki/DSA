#include<iostream>
using namespace std;
char toLowerCase(char ch) {
    if((ch >='a' && ch <='z')||(ch >='0' && ch <='9'))
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(toLowerCase( a[s] ) != toLowerCase( a[e] ) )
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}
int main(){
    char ch[20];
    cin>>ch;
    int len = getLength(ch);

    cout<<"Is Palindrome = "<< checkPalindrome(ch,len)<<endl;
}