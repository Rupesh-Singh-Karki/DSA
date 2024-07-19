#include<iostream>
#include<unordered_map>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
class Solution{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->random != NULL) {
                cout << " head random data" << head -> random ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head){
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }

        //step 2 create a map
        unordered_map<Node*, Node*>oldtonewnode;

        Node* originalnode = head;
        Node* clonenode = cloneHead;
        while(originalnode !=NULL && clonenode !=NULL){
            oldtonewnode[originalnode]=clonenode;
            originalnode = originalnode -> next;
            clonenode = clonenode -> next;
        }

        originalnode = head;
        clonenode = cloneHead;

        while(originalnode !=NULL){
            clonenode -> random = oldtonewnode[originalnode -> random];
            originalnode = originalnode -> next;
            clonenode = clonenode -> next;
        }
        return cloneHead;
    }
};