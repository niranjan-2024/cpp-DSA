void inorder(Node* root,vector<int> &in){
    if(root==NULL){
       return;
    }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
Node* intoBST(int s,int e,vector<int> in){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = intoBST(s,mid-1,in);
    root->right = intoBST(mid+1,e,in);
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<int> in;
	inorder(root,in);
	return intoBST(0,in.size()-1,in);
}
