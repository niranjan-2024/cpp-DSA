class Solution{
    public:
    void createmapping(int in[],map<int,int> &nodetoindex,int n){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]] = i;
        }
    }
    
    Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n,map<int,int> &nodetoindex){
         if(index>=n || inorderstart>inorderend){
             return NULL;
          }
         int element = pre[index++];
         Node* root = new Node(element);
         int position = nodetoindex[element];
         root->left = solve(in,pre,index,inorderstart,position-1,n,nodetoindex);
         root->right = solve(in,pre,index,position+1,inorderend,n,nodetoindex);
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex = 0;
        map<int,int> nodetoindex;
        createmapping(in,nodetoindex,n);
        Node* ans = solve(in,pre,preorderindex,0,n-1,n,nodetoindex);
        return ans;
    }
};
