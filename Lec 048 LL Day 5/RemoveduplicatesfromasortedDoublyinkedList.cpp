/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
   if (head == nullptr || head->next == nullptr) {
        return NULL;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicateNode = current->next;
            current->next = duplicateNode->next;

            // Check if the next node is not the last node
            if (current->next != nullptr) {
                current->next->prev = current;
            }

            delete duplicateNode;
        } else {
            current = current->next;
        }
    }
    return head;
    
}
