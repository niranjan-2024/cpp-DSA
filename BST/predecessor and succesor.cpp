Node * Success(Node * root)
{
   Node * curr = root->right;
   while(curr->left!=NULL)
       curr=curr->left;
   return curr;
}
Node * Predecer(Node * root)
{
   Node * curr = root->left;
   while(curr->right!=NULL)
       curr=curr->right;
   return curr;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   if(root==NULL)
       return;
       
   if(root->key == key)
   {
       if(root->right) 
           suc=Success(root);
           
       if(root->left) 
           pre=Predecer(root);
       return;
   }
   
   if(root->key < key)
   {
       pre =root;
       findPreSuc(root->right,pre,suc,key);
   }
   
   else if(root->key > key)
   {
       suc =root;
       findPreSuc(root->left,pre,suc,key);
   }
}
