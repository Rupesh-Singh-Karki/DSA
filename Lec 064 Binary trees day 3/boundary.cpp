class Solution {
public:
    void lefttraversal(Node *root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            lefttraversal(root->left,ans);
        }
        else{
            lefttraversal(root->right,ans);
        }
    }
    void leaftraversal(Node *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        leaftraversal(root->left,ans);
        leaftraversal(root->right,ans);
        
        
    }
    void righttraversal(Node *root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            righttraversal(root->right,ans);
        }
        else{
            righttraversal(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        lefttraversal(root->left,ans);
        
        //leftleaf
        leaftraversal(root->left,ans);
        //rightleaf
        leaftraversal(root->right,ans);
        
        righttraversal(root->right,ans);
        
        return ans;
    }
};