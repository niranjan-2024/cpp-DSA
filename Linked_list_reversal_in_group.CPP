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

struct node *reverse (struct node *head, int k)
{
	if (!head)
		return NULL;

	struct node* current = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if (next != NULL)
	head->next = reverse(next, k);
  
	return prev;
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
   
   linkedlisttraversal(head);
   head = reverse(head,4);
   cout << endl;
   linkedlisttraversal(head);
   
   return 0;
}
