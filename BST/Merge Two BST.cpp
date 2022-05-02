class Solution
{
    void BSTtoDLL(Node *root, Node* &head)
    {
    	if(!root) return;
    	BSTtoDLL(root->right, head);
    	root->right = head;
    	if(head != NULL)
    		head->left = root;
    	head = root;
    	BSTtoDLL(root->left, head);
    }
    
    Node *mergeSortedDLL(Node *head1, Node *head2)
    {
    	if(!head1) return head2;
    	if(!head2) return head1;
    	Node *head = NULL;
    	Node *tail = NULL;
    	
    	while(head1 != NULL && head2 != NULL)
    	{
    		if(head1->data < head2->data)
    		{
    			if(head == NULL)
    			{
    				head = tail = head1;
    				head1 = head1->right;
    			}
    			else
    			{
    				tail->right = head1;
    				head1->left = tail;
    				tail = head1;
    				head1 = head1->right;
    			}
    		}
    		else
    		{
    			if(head == NULL)
    			{
    				head = tail = head2;
    				head2 = head2->right;
    			}
    			else
    			{
    				tail->right = head2;
    				head2->left = tail;
    				tail = head2;
    				head2 = head2->right;
    			}
    		}
    	}
    	while(head1)
    	{
    		tail->right = head1;
    		head1->left = tail;
    		tail = head1;
    		head1 = head1->right;
    	}
    	while(head2)
    	{
    		tail->right = head2;
    		head2->left = tail;
    		tail = head2;
    		head2 = head2->right;
    	}
    	
    	return head;
    }
  
    int countNodes(Node *&head)
    {
    	int count = 0;
    	Node *curr = head;
    	while(curr)
    	{
    		count++;
    		curr = curr->right;
    	}
    	return count;
    }
  
    vector<int> DLLtoInorder(Node *&head)
    {
        vector<int> inorder;
        if(!head) return inorder;
        while(head)
        {
            inorder.push_back(head->data);
            head = head->right;
        }
        return inorder;
    }
  
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       // Step1: convert BST to DLL
    	Node * head1 = NULL, *head2 = NULL;
    	BSTtoDLL(root1, head1);
    	head1->left = NULL;
    	BSTtoDLL(root2, head2);
    	head2->left = NULL;
    	
    	// Step2: merge two DLL
    	Node *mergedDLL = mergeSortedDLL(head1, head2);
    	
    	// Step3: convert sorted DLL to vector
    	return DLLtoInorder(mergedDLL);
    }
};
