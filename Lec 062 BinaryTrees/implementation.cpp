#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data =d;
        this -> left = nullptr;
        this -> right = nullptr;
    }

};

node* buildtree(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting at left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter the data for inserting at right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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
//1 2 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
/*void reverseordertraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(q.front()==NULL){ //purana lvl complete ho chuka hai
            cout<<endl;
            if(!q.empty()){ //queue still  has some child nodes
                q.push(NULL);
                s.push(NULL);
            }
        }
        else{
            s.push(temp->data);
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        if(s.top()==NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
    }
}
*/

void inorder(node* root) { //try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {//try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {//try without recurrsion
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main(){
    node* root = NULL;
    root = buildtree(root);
    //creating a Tree
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the reverse level order tracersal output " << endl;
    reverseordertraversal(root);

    return 0;
}