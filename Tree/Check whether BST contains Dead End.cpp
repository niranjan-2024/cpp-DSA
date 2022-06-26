bool find(Node* curr,int start,int end){
    if(curr==NULL){
        return false;
    }
    if(start==end){
        return true;
    }
    bool l = find(curr->left,start,curr->data-1);
    bool r = find(curr->right,curr->data+1,end);
    return(r||l);
}

bool isDeadEnd(Node *root)
{
    int start = 1,end = INT_MAX;
    return find(root,start,end);
}
