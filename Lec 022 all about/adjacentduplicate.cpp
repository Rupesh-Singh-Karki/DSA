#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {

		string ans;
		ans.push_back(s[0]);

		for(int i=1 ; i<s.length() ; i++){

			if(!ans.empty() && s[i] == ans.back()){ //checks if ans is not empty and last element is same or not
				ans.pop_back();  //pop last element kyuki same hoga woh next wale sai
			}
			else{
				ans.push_back(s[i]); //not same toh put kardo value
			}
		}

		return ans;
	}
};