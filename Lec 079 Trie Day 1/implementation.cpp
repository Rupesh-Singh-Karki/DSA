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
        int index = word[0] - 'A';
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

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isterminal;
        }

        //assumptions word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index]; //point child to children if exist
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    void search(string word){
        searchUtil(root,word);
    }
};
