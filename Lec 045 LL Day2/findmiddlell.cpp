/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int getlength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }

    return len;

}
Node *findMiddle(Node *head) {
    int len = getlength(head);
    int ans= len/2; //(len/2)+1 was for postion of middle node but here it will reach one step aahead of the middle term

    Node* temp=head;
    int cnt =0;

    while(cnt<ans){
        temp = temp -> next;
        cnt++;
    }

    return temp;
}

