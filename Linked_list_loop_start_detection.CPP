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
node* detectLoop(node* head)
{

	// Create a temporary node
	node* temp = new node;
	while (head != NULL) {

		// This condition is for the case
		// when there is no loop
		if (head->next == NULL) {
			return NULL;
		}

		// Check if next is already
		// pointing to temp
		if (head->next == temp) {
			break;
		}

		// Store the pointer to the next node
		// in order to get to it in the next step
		node* nex = head->next;

		// Make next point to temp
		head->next = temp;

		// Get to the next node in the list
		head = nex;
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
   
   head->next->next->next->next->next->next->next->next->next->next = head->next;
   
  // detectAndRemoveLoop(head);
   //linkedlisttraversal(head);
  /* if(detectLoop(head)){
      cout << "loop is present" <<endl;
   }
   else{
      cout << "no loop" << endl;
   }*/
   node* res = detectLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->data;


   return 0;
}
