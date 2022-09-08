class Solution{
  public:
  
    void inorderTraversal(Node* root,vector<int> &inorder){
        if(root==NULL){
            return;
        }
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right,inorder);
    }
    
    void fillPostOrder(Node* root,vector<int> &inorder,int &i){
         if(root == NULL) return;
        fillPostOrder(root->left,inorder,i);
        fillPostOrder(root->right,inorder,i);
        root->data = inorder[i++];
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        int i=0;
        fillPostOrder(root,inorder,i);
    }    
};
