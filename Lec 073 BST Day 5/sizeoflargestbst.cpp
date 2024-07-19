/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;

};
info solve(TreeNode* root, int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info current;
    current.size = left.size+right.size+1;
    current.maxi = max(root->data,right.maxi);
    current.mini = min(root->data,left.mini);

    if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini)){
        current.isbst = true;
        
    }
    else{
        current.isbst =false;
    }

    if(current.isbst){
        ans = max(ans,current.size);
    }

    return current;
}
int largestBST(TreeNode * root){
    int maxsize = 0;
    info temp = solve(root,maxsize);
    return maxsize;
}