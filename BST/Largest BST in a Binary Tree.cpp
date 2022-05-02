class Solution{
    public:
    
    class info{
        public:
        int max;
        int min;
        bool isBST;
        int size;
    };
    
    info solve(Node* root,int &ans){
        if(root==NULL){
            return{INT_MIN,INT_MAX,true,0};
        }
        
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info currNode;
        
        currNode.size = left.size+right.size+1;
        currNode.max = max(root->data,right.max);
        currNode.min = min(root->data,left.min);
        
        if(left.isBST && right.isBST && root->data>left.max && root->data<right.min){
            currNode.isBST = true;
        }
        else{
            currNode.isBST = false;
        }
        
        if(currNode.isBST){
            ans = max(ans,currNode.size);
        }
        return currNode;
    }
    
    int largestBst(Node *root)
    {
       int maxsize=0;
       info temp = solve(root,maxsize);
       return maxsize;
    }
};
