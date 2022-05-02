class Solution {
  public:
 void inorder(Node* root, int &K, int &ans)
             {
                 if(!root) return;
                 
                 inorder(root->right,K,ans);
                 
                 K--;
                 if(K==0)
                 {
                     ans = root->data;
                     return;
                 }
                 
                 inorder(root->left,K,ans);
             }
    // Return the Kth smallest element in the given BST
    int kthLargest(Node *root, int K) {
         int ans = -1;
         inorder(root,K,ans);
         return ans;
    }
};
