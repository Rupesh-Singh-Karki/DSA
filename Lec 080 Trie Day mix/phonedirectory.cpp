#include<iostream>
using namespace std;

class TrieNode{
    public:

    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class trie {
    public:
    TrieNode* root;

    trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isterminal = true;
            return;
        }

        //assumptions word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index]; //point child to children if exist
        }
        else{
            child = new TrieNode(word[0]);//create child
            root->children[index] = child;//point children at child
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    void printsuggestion(TrieNode* curr, vector<string> &temp, string prefix){
         if(curr->isterminal){
             temp.push_back(prefix);
         }

         for(char ch = 'a' ; ch <= 'z'; ch++){
             TrieNode* next = curr->children[ch-'a'];

             if(next!=NULL){
                prefix.push_back(ch);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
             }
         }
    }

    vector<vector<string>> getsuggestion(string str) {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0;i<str.length();i++){
            char lastch = str[i];
            prefix.push_back(lastch);


            //check for lastch
            TrieNode* curr = prev->children[lastch-'a'];

            //if not found
            if(curr==NULL){
                break; 
            }

            //if found
            vector<string> temp;
            printsuggestion(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;

        }

        return output;
    }

};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    trie* t = new trie();

    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertword(str);
    }

    return t->getsuggestion(queryStr);
}