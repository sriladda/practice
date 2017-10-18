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

void printList(struct Node* head)
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

Node* reverseKNodes(Node *head, int size)
{
    Node *p, *q, *new_start, *start = head, *temp;
    Node *prev;
    int count;

    for(count = 1, p = head; count < size; count++)
    {
        p = p->next;
    }
    new_start = p;

    while(start)
    {
        p = start;
        q = p;
        for(count = 1; count < size && q; count++)
        {
            q = q->next;
        }
        if (q)
        {
            start = q->next;
            temp = q->next;
            q->next = NULL;
        }
        for(count = 1; count < size && temp; count++)
        {
            temp = temp->next;
            //printf("temp->data = %d\n", temp->data);
        }
        //If there are no k blocks in this sublist, do not reverse the last sublist, starting from q and temp.
        printf("count = %d size = %d\n", count, size);
        if (count <size)
        {
            prev = reverse(p);
            p->next = start;
            return new_start;
        }
        prev = reverse(p);
        p->next = temp;
        
        //printf("p->data = %d temp->data = %d\n", p->data, temp->data);
    }
    printList(new_start);
    return new_start;
}
    
/* Driver program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9->10 */
     push(&head, 10);
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\nGiven linked list \n");
     printList(head);
     head = reverseKNodes(head, 3);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}
