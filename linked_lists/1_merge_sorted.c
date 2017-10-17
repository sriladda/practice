/* C/C++ program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node *node);

struct Node * SortedMerge(struct Node* headA, struct Node* headB)
{
  struct Node *result_head = NULL, *temp, *result, *currA, *currB;

  if(headA == NULL) return headB;
  if (headB == NULL) return headA;

  for( result = result_head, currA = headA, currB= headB; currA && currB;)
  {
      if (currA->data < currB->data)
      {
          if (result == NULL)
          {
              result = currA;
              result_head = result;
          }
          else 
          {
              result->next = currA;
              result = result->next;
          }
          currA = currA->next;
      }
      else if (currB->data < currA->data)
      {
          if (result == NULL)
          {
              result = currB;
              result_head = result;
          }
          else 
          {
              result->next = currB;
              result = result->next;
          }
          currB = currB->next;
      }
  }
  printList(result);
  if (currA)
  {
      result->next = currA;
  }
  else if (currB)
  {
      result->next = currB;
  }
  return result_head;

}

/* Function to insert a node at the beginging of the
   linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;

    /* Let us create two sorted linked lists to test
 *       the functions
 *              Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 6);
    push(&a, 5);
    push(&a, 3);
    push(&a, 1);

    push(&b, 7);
    push(&b, 4);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printList(a);
    printf(" printf a \n");
    printList(b);
    printf(" printed b\n");
    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
