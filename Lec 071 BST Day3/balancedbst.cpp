/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root,vector<int> &inoval){
    if(root==NULL){
        return;
    }

    inorder(root->left,inoval);
    inoval.push_back(root->data);
    inorder(root->right,inoval);
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
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inoval;
    inorder(root,inoval);

    return inordertobst(0, inoval.size()-1,inoval);
}
