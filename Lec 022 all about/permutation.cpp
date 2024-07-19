#include<iostream>
using namespace std;

class Solution {
private:
    bool ifequal(int a[26],int b[26]){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]){
                return 0;

            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        

        //geting count for comparison
        int count1[26]={0};
        for(int i=0; i<s1.size(); i++ ){
            int index= s1[i]-'a';
            count1[index]++;
        }

        int i=0;
        int count2[26]={0};
        int windsize= s1.length();
        
        //first windwo run
        while(i<windsize && i<s2.length()){
            int index= s2[i]-'a'; //yeh isliye banaya pehle taki windiow create hp jaye 
            count2[index]++;
            i++;
        }
        if(ifequal(count1,count2)){
            return 1;
        }
        
        //aage window process karo
        while(i<s2.length()){  //abb window bam chaki hai
            char newchar=s2[i];
            int index=newchar-'a';
            count2[index]++;

            char oldchar=s2[i-windsize];
            index = oldchar-'a';
            count2[index]--;
            i++;

            if(ifequal(count1,count2)){
            return 1;
            }

        }
        return 0;
        
    }
};