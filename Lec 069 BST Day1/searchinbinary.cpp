bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(x>root->data){
        searchInBST(root->right,x);
    }
    else{
        searchInBST(root->left,x);
    }
}

//iterative method
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;

    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }

        if(x>temp->data){
            temp=temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
}