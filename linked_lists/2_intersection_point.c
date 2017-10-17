//http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};

/* Function to get the counts of node in a linked list */
int getCount(struct Node* head);

int getIntesectionNode(struct Node *list1, struct Node *list2)
{
    int len1,len2;

    len1 = getCount(list1);
    len2 = getCount(list2);

    if(len1 > len2)
    {
        return _getIntesectionNode(len1-len2, list1, list2);
    }
    else if(len2 > len1)
    {
        return _getIntesectionNode(len2-len1, list2, list1);
    }
}

/* function to get the intersection point of two linked
 *    lists head1 and head2 where head1 has d more nodes than
 *       head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2);

int _getIntesectionNode(int d, struct Node* head1, struct Node* head2)
{
    int count;

    for(count = 0; count < d; count++)
    {
        head1 = head1->next;
    } 
    while(head1 && head2)
    {
        if (head1->data == head2->data)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

/* Takes head pointer of the linked list and
 *    returns the count of nodes in the list */
int getCount(struct Node* head)
{
  struct Node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

/* IGNORE THE BELOW LINES OF CODE. THESE LINES
 *    ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
 *     Create two linked lists
 *      
 *          1st 3->6->9->15->30
 *              2nd 10->15->30
 *               
 *                   15 is the intersection point
 *                     */
 
  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;
 
  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));
 
}
