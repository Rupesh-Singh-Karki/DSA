/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode* root,vector<int> &inoval){ //approach 1
    if(root==NULL){
        return;
    }

    inorder(root->left,inoval);
    inoval.push_back(root->data);
    inorder(root->right,inoval);
}
vector<int> mergearray(vector<int> bst1,vector<int> bst2){
    int i=0;
    int j=0;
    int k=0;

    vector<int> ans(bst1.size()+bst2.size());
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans[k++]=bst1[i++];
        }
        else{
            ans[k++]=bst2[j++];
        }
    }

    while(i<bst1.size()){
        ans[k++]=bst1[i++];
    }
    while(j<bst2.size()){
        ans[k++]=bst2[j++];
    }

    return ans;
}
TreeNode<int>* inordertobst(int s,int e,vector<int> inoval){ //yaha par reference dene sia kai baar tle hat skta hai
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inoval[mid]);
    root->left =inordertobst(s, mid-1,inoval); 
    root->right=inordertobst(mid+1, e,inoval);
    return root;
}
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> merged = mergearray(bst1,bst2);
    int s=0;
    int e=merged.size()-1;
    return inordertobst(s,e,merged);
}