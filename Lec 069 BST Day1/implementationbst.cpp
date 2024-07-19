#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left=NULL;
        this->right=NULL;
    }


};
Node* insertbst(Node* root,int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->data){
        insertbst(root->right,d);
    }
    else{
        insertbst(root->left,d);
    }

    return root;

}

/*TreeNode* insertIntoBST(TreeNode* root, int val) { //also correct
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}*/


void takeinput(Node* root){
    int d;
    cin>>d;

    while(d != -1){
        insertbst(root,d);
        cin>>d;
    }
}
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }

    return temp;
}

Node* deletefrombst(Node* root, int val){
    //base case
    if(root==NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left !=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;

        }
        //right child
        if(root->left == NULL && root->right!=NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right !=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletefrombst(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deletefrombst(root->left,val);
        return root;
        /*If the value to be deleted is smaller than 
        the current node's data, the node to be deleted is in the left subtree. 
        Therefore, you call deletefrombst on the left subtree and reassign root->left
        to ensure the updated subtree is correctly connected to the current node.*/
    }
    else{
        root->right = deletefrombst(root->right,val);
        return root;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){ //purana lvl complete ho chuka hai
            cout<<endl;
            if(!q.empty()){ //queue still  has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inorder(Node* root) { //try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {//try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {//try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main(){
    Node* root = NULL;
    cout<<"Enter data for bst"<<endl;

    takeinput(root);
}