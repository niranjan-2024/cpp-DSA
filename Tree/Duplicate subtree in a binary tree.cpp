class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string,int> map;
    
    string AllSubtreeMapping(Node* root){
        if(root==NULL){
            return "$";
        }
        string s = "";
        if(root->right==NULL && root->left==NULL){
            s = to_string(root->data);
            return s;
        }
        s+=to_string(root->data);
        s+=AllSubtreeMapping(root->left);
        s+=AllSubtreeMapping(root->right);
        map[s]++;
        return s;
    }
    
    int dupSub(Node *root) {
        AllSubtreeMapping(root);
        for(auto x: map){
            if(x.second>=2){
                return 1;
            }
        }
        return 0;
    }
};
