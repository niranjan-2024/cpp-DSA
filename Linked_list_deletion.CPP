#include<bits/stdc++.h>
using namespace std;
struct node{
   int data;
   struct node* next;
};

void linkedlisttraversal(struct node* node)
{
   while(node!=NULL)
   {
      cout << node->data << endl;
      node = node->next;
   }
}

struct node* insertatfirst(struct node* head, int data)
{
   struct node* ptr = (struct node*)malloc(sizeof(struct node));
   ptr->next = head;
   ptr->data = data;
   return ptr;
}

struct node* insertatindex(struct node* head, int data, int index)
{
   struct node* ptr = (struct node*)malloc(sizeof(struct node));
   struct node* p = head;
   int i = 0;
   while(i!=index-1)
   {
      p = p->next;
      i++;
   }
   ptr->data = data;
   ptr->next = p->next;
   p->next = ptr;
   return head;
}

struct node* insertatend(struct node* head,int data)
{
   struct node* ptr = (struct node*)malloc(sizeof(struct node));
   ptr->data = data;
   struct node* p = head;
   while(p->next!=NULL)
   {
      p = p->next;
   }
   p->next = ptr;
   ptr->next = NULL;
   return head;
}

struct node* insertafter(struct node* head, struct node* prevnode, int data)
{
   struct node* ptr = (struct node*)malloc(sizeof(struct node));
   ptr->data = data;
   ptr->next = prevnode->next;
   prevnode->next = ptr;
   return head;
}

struct node* deletefirst(struct node* head)
{
   struct node* ptr = head;
   head = head->next;
   free(ptr);
   return head;
}

struct node* deleteatindex(struct node* head, int index)
{
   struct node* p = head;
   struct node* q = head->next;
   
   for(int i = 0;i < index - 1;i++)
   {
      p = p->next;
      q = q->next;
   }
   p->next = q->next;
   free(q);
   return head;
}

struct node* deletelast(struct node* head)
{
   struct node* p = head;
   struct node* q = head->next;
   while(q->next!=NULL)
   {
      p = p->next;
      q = q->next;
   }
   p->next = NULL;
   free(q);
   return head;
}

struct node* deletevalue(struct node* head, int value)
{
   struct node* p = head;
   struct node* q = head->next;
   
   while((q->data!=value)&&(q->next!=NULL))
   {
      p = p->next;
      q = q->next;
   }
   
   if(q->data == value)
   {
      p->next = q->next;
      free(q);
   }
   return head;
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
   
   fifth->data = 6;
   fifth->next = sixth;
   
   sixth->data = 7;
   sixth->next = seventh;
   
   seventh->data = 8;
   seventh->next = eigth;
   
   eigth->data = 9;
   eigth->next = ninth;
   
   ninth->data = 10;
   ninth->next = NULL;
   
   //head = insertatfirst(head,0);
   //head = insertatindex(head,100,6);
   //head = insertatend(head,200);
   //head = insertafter(head,seventh,50);
   
   head = deletefirst(head);
   head = deleteatindex(head, 6);
   head = deletelast(head);
   head = deletevalue(head,6);
   
   
   linkedlisttraversal(head);
   
   return 0;
}
