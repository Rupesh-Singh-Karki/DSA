#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
void inorder(BinaryTreeNode<int>* root,vector<int> &inoval){
    if(root==NULL){
        return;
    }

    inorder(root->left,inoval);
    inoval.push_back(root->data);
    inorder(root->right,inoval);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inoval;
    inorder(root,inoval);

    int i =0;
    int j = inoval.size()-1;
    while(i<j){
        int sum = inoval[i]+inoval[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}