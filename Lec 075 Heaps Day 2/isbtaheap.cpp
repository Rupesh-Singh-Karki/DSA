// User Function template for C++
// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class Solution {
  public:
    int countnodes(struct Node* tree){
        //base case
        if(tree==NULL){
            return 0;
        }
        
        int ans = 1+countnodes(tree->left)+countnodes(tree->right);
        return ans;
    }
    bool isCBT(struct Node* tree , int index, int cnt){
        if(tree==NULL){
            return true;
        }
        
        if(index>=cnt){
            return false;
        }
        else{
            bool left = isCBT(tree->left,2*index+1,cnt);
            bool right = isCBT(tree->right,2*index+2,cnt);
            return(left&&right);
        }
    }
    
    bool ismaxorder(struct Node* tree){
        //leaf node
        if(tree->left == NULL && tree->right == NULL){
            return true;
        }
        
        if(tree->right==NULL){
            return (tree->data>tree->left->data);
        }
        
        else{
            bool left = ismaxorder(tree->left);
            bool right = ismaxorder(tree->right);
            return (left && right && (tree->data>tree->left->data && tree->data>tree->right->data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalcount = countnodes(tree);
        if(isCBT(tree,index,totalcount)&& ismaxorder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};