void inorder(TreeNode<int>* root,vector<int> &inoval){
    if(root==NULL){
        return;
    }

    inorder(root->left,inoval);
    inoval.push_back(root->data);
    inorder(root->right,inoval);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inoval;
    inorder(root,inoval);
    int n = inoval.size();
    TreeNode<int>* newroot = new TreeNode<int>(inoval[0]);
    TreeNode<int>* curr = newroot;

    //2nd case
    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inoval[i]);
        curr->right = temp;
        curr->left=NULL;
        curr = temp;
    }

    //3rd case
    curr->left=NULL;
    curr->right=NULL;

    return newroot;
}