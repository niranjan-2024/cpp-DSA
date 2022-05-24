class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
       int len=strlen(key);
       for(int i=0;i<len;i++)
       {
           char ch=key[i];
           if(root->children[ch-'a'])
           {
              root->children[ch-'a']->value=0;
           }
           root=root->children[ch-'a'];
       }
    }
};
