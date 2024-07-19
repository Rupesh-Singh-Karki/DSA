#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansindex=0;
        int n=chars.size();

        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++; //traversing until similar elemt is over
            }
            chars[ansindex++]=chars[i]; //character stored
            int count=j-i; //count stored
            if(count>1){
                string cnt = to_string(count); //converts int to string
                for(char ch:cnt){
                    chars[ansindex++]=ch; //count character stored
                }
            }
            i=j;
        }
        return ansindex;


        
    }
};