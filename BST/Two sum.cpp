class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void inorder(Node* root,vector<int> &inorderval){
        if(root==NULL){
            return;
        }
        inorder(root->left,inorderval);
        inorderval.push_back(root->data);
        inorder(root->right,inorderval);
    }
    int isPairPresent(struct Node *root, int target)
    {
       vector<int> inorderval;
       inorder(root,inorderval);
       int i = 0;
       int j = inorderval.size()-1;
       while(i<j){
           int sum = inorderval[i]+inorderval[j];
           if(sum == target){
               return 1;
           }
           else if(sum>target){
               j--;
           }
           else{
               i++;
           }
       }
       return 0;
    }
};
