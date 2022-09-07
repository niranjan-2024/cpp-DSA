class Solution {
  public:
  
    bool isMaxOrder(struct Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            if(left && right && root->data > root->left->data && root->data > root->right->data){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    bool isCBT(struct Node* root,int index,int totalNodes){
        if(root==NULL){
            return true;
        }
        if(index>=totalNodes){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index+1,totalNodes);
            bool right = isCBT(root->right,2*index+2,totalNodes);
            return left && right;
        }
    }
    
    int count(struct Node* root){
        if(root==NULL){
            return 0;
        }
        int ans = 1 + count(root->left) + count(root->right);
        return ans;
    }
    
    bool isHeap(struct Node* root) {
        int index = 0;
        int totalNodes = count(root);
        if(isCBT(root,index,totalNodes) && isMaxOrder(root)){
            return true;
        }
        else{
            return false;
        }
    }
};
