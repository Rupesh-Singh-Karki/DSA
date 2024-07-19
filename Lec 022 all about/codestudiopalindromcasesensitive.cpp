#include <bits/stdc++.h> 

 

// creating a function to check the validity of the character

bool isValid(char ch){

    if(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z' || ch>='0'&&ch<='9'){

        return true;

    }

    return false;

}

 

bool checkPalindrome(string s)

{

    int start = 0;

    int end = s.length()-1;

 

    while(start<=end){

        if(isValid(s[start])){

            if(isValid(s[end])){

                if( tolower(s[start]) != tolower(s[end]) ){

                    return false;

                }

                else{

                    start++;

                    end--;

                }

            }

            else{

                end--;

            }

        }

        else{

            start++;

        }

    }

 

    return true;

}