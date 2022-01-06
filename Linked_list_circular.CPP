#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node* next;
};

void linkedlisttraversal(struct node* head)
{
   struct node* ptr = head;
   do{
      cout << ptr->data << endl;
      ptr = ptr->next;
   }while(ptr!=head);
}

struct node* insertatfirst(struct node* head, int data)
{
   struct node* ptr = (struct node*)malloc(sizeof(struct node));
   ptr->data = data;
   struct node* p = head->next;
   while(p->next!=head)
   {
      p = p->next;
      
   }
   p->next = ptr;
   ptr->next = head;
   head = ptr;
   return head;
}

int main()
{
   struct node* head;
   struct node* first;
   struct node* second;
   
   head = (struct node*)malloc(sizeof(struct node));
   first = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   
   head->data = 1;
   head->next = first;
   
   first->data = 2;
   first->next = second;
   
   second->data = 3;
   second->next = head;
head = insertatfirst(head, 0);
linkedlisttraversal(head);
   return 0;
}
