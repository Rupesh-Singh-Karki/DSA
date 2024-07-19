#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){  //pehli condition ki pura string delete ho jaye to bahar ajao
                                                         //second pehle check karega position part kii phir compare karega ki woh length sai kam hai mtlb available hai ki nhi
            s.erase(s.find(part),part.length());         //erase function remove kardega part.length() bata hai ki kitna elet karna hai
        }
        return s;
    }
};