/*Given a signed 32-bit integer x, return x with its digits reversed.
 If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).*/
//leetcode ka answer hai yeh
#include<iostream>
using namespace std;
int reverse(int x) {
        int ans=0;
        while(x!=0){
            int digit= x%10;
            if((ans>INT32_MAX/10)||(ans<INT32_MIN/10)){
                return 0;
            }
            ans=(ans*10)+digit;
            x=x/10;

        }
        return ans;
    }
