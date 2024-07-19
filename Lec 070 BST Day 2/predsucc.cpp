pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    int succ = -1;
    int pred = -1;
    TreeNode* temp = root;

    // Find the node with the given key
    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;  // Potential successor
            temp = temp->left;
        } else {
            pred = temp->data;  // Potential predecessor
            temp = temp->right;
        }
    }

    // If the key is not found in the tree
    if (temp == NULL) {
        return make_pair(pred, succ);
    }

    // Find the maximum value in the left subtree for the predecessor
    TreeNode* lefttree = temp->left;
    while (lefttree != NULL) {
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    // Find the minimum value in the right subtree for the successor
    TreeNode* righttree = temp->right;
    while (righttree != NULL) {
        succ = righttree->data;
        righttree = righttree->left;
    }

    return make_pair(pred, succ);
}
