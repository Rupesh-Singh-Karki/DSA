//approach 1
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    for(int i =0; i<arr[0].length(); i++){ //traversing first string of arr
        char ch  = arr[0][i];
        bool match = true;

        for(int j=1; j<n;j++){ // comparing to other remaining strings
            if(arr[j].size()<i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }

        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }

    return ans;
}

//aproach 2
class TrieNode{
    public:

    char data;
    TrieNode* children[26];
    int childcount;
    bool isterminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childcount = 0;
        isterminal = false;
    }
};

class trie {
    public:
    TrieNode* root;

    trie(char ch) {
        root = new TrieNode(ch);
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
            root->childcount++;
            root->children[index] = child;//point children at child
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    void lcp(string str, string &ans){
        for(int i=0;i<str.length(); i++){
            char ch = str[i];

            if(root->childcount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }

            else{
                break;
            }

            if(root->isterminal){
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    trie* t = new trie('\0');

    for (int i = 0; i < n; i++) {
        t->insertword(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}// partially accepted



