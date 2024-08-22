#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {  //if (this->next != NULL): Checks if the next node (this->next) exists.
            delete next;  //delete next;: Deletes the next node, and in doing so, calls the destructor of the next node recursively (if it exists).
            this->next = NULL; //this->next = NULL;: Sets the next pointer to NULL after deleting it to avoid any dangling pointers.
        }
        cout << " memory is free for node with data " << value << endl;
        /*This destructor is designed to free the memory of the current node and all subsequent nodes in the linked 
        list by recursively calling the destructor for each subsequent node. It helps prevent memory leaks by 
        releasing the dynamically allocated memory used by the linked list nodes when the linked list goes out
         of scope or is explicitly deleted.*/
    }

};

void InsertAtHead(node* &head, int d){ 
    /*he head parameter is passed by reference (&), which means any changes made 
    to head inside the function will affect the original head outside the function.*/
    //new node create 
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(node* &tail, int d){
    //new node create 
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
    
}

void InsertAtMiddle(node* &tail ,node* &head, int position, int d){
    if(position ==1){
        InsertAtHead(head, d);
        return;
    }
    node* temp =head;
    int cnt =1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){ //yeh isliye jaRURI tha kyuki element add ho jata but tail update nhi hota last par 
        InsertAtTail(tail,d);
        return;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

void deletenode(int position, node* & head){
    if(position ==1){
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* prev = NULL;
        int cnt = 1;

        while(cnt <position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }

}

void print(node* &head){ //& was not necessary but used so that hum memory bacha sake
    node* temp =head;

    while(temp != NULL){
        cout<<temp -> data <<" "; //printing head
        temp = temp -> next; //changing position of temp from head to next number
    }
}

int main(){

    node* node1 = new node(10);
    //cout<<node1 -> data <<endl;
    //cout<<node1 -> next <<endl;

    //head point to node 1;
    node* head=node1;
    node* tail=node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);

    return 0;

}