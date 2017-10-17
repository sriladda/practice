//http://www.geeksforgeeks.org/reverse-sublist-linked-list/
//C program to reverse a linked list
// from position m to position n
#include <stdio.h>
#include <stdlib.h>
  
// Linked list node
struct Node {
    int data;
    struct Node* next;
};
           
// the standard reverse function used
// to reverse a linked list
struct Node* reverse(struct Node* head)
{
    struct Node* prev = NULL;    
    struct Node* curr = head;
                    
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
 
//function to add a new node at the
// begining of the list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
    
Node* reverseBetween(Node *head, int m, int n)
{
    Node *curr, *revs, *revs_prev, *revind, *revind_next = NULL;
    int count;
    if (head == NULL) return NULL;

    for(count = 0; count < n; count++)
    {
        if(count < m)
        {
            printf("curr->data = %d\n", curr->data);
            revs_prev = curr;
        }
        else if(count == m)
        {
            printf("curr->data at m position = %d\n", curr->data);
            revs = curr;
        }
        else if(count == n)
        {
            revind_next = curr;
        }
        curr= curr->next;
    }
    revind = reverse(revs);
    revs_prev->next = revind;
    return head;
}
              
// Driver code
int main()
{
    struct Node* head = NULL;
    push(&head, 70);
    push(&head, 60);
    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    reverseBetween(head, 3, 6);
    print(head);
    return 0;
}
