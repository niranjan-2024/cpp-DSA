#include<bits/stdc++.h>
using namespace std;
struct node{
   int data;
   struct node* next;
   int flag;
};

void linkedlisttraversal(struct node* node)
{
   while(node!=NULL)
   {
      cout << node->data << endl;
      node = node->next;
   }
}

void removeDuplicates(struct node* head)
{
    /* Pointer to traverse the linked list */
    struct node* current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next; 
  
    /* do nothing if the list is empty */
    if (current == NULL) 
       return; 

    /* Traverse the list till last node */
    while (current->next != NULL) 
    {
       /* Compare current node with next node */
       if (current->data == current->next->data) 
       {
           /* The sequence of steps is important*/               
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next; 
       }
    }
}

int main()
{
   struct node* head;
   struct node* first;
   struct node* second;
   struct node* third;
   struct node* fourth;
   struct node* fifth;
   struct node* sixth;
   struct node* seventh;
   struct node* eigth;
   struct node* ninth;
   
   head = (struct node*)malloc(sizeof(struct node));
   first = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));
   fourth = (struct node*)malloc(sizeof(struct node));
   fifth = (struct node*)malloc(sizeof(struct node));
   sixth = (struct node*)malloc(sizeof(struct node));
   seventh = (struct node*)malloc(sizeof(struct node));
   eigth = (struct node*)malloc(sizeof(struct node));
   ninth = (struct node*)malloc(sizeof(struct node));
   
   head->data = 1;
   head->next = first;
   
   first->data = 2;
   first->next = second;
   
   second->data = 3;
   second->next = third;
   
   third->data = 4;
   third->next = fourth;
   
   fourth->data = 5;
   fourth->next = fifth;
   
   fifth->data = 5;
   fifth->next = sixth;
   
   sixth->data = 7;
   sixth->next = seventh;
   
   seventh->data = 8;
   seventh->next = eigth;
   
   eigth->data = 10;
   eigth->next = ninth;
   
   ninth->data = 10;
   ninth->next = NULL;
   
   linkedlisttraversal(head);
 removeDuplicates(head);
 cout << endl;
 linkedlisttraversal(head);
   
  


   return 0;
}
