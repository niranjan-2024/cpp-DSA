class Solution{
public:

    class TrieNode{
        
        public:
          char ch;
          TrieNode* children[26];
          bool isEnd;
          
          TrieNode(char data){
              ch = data;
              for(int i=0; i<26; i++){
                  children[i] = NULL;
              }
              isEnd = false;
          }
        
    };
    
    class Trie{
        public:
            TrieNode* root;
            
            Trie(){
                this->root = new TrieNode('\0');
            }
            
            void insertUtil(TrieNode* root, string x){
        
                if(x.size() == 0){
                    root->isEnd = true;
                    return;
                }
                
                int index = x[0] - 'a';
                
                TrieNode* child;
                
                if(root->children[index] != NULL){
                    child = root->children[index];
                }
                else{
                    child = new TrieNode(x[0]);
                    root->children[index] = child;
                }
                
                insertUtil(child, x.substr(1));
            
            }
            
            void insert(string x){
                insertUtil(root, x);
            }
    
    
            void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
        
                if(curr->isEnd){
                    temp.push_back(prefix);
                }
                
                for(char ch = 'a'; ch <= 'z'; ch++){
                    TrieNode* next = curr->children[ch-'a'];
                    
                    if(next != NULL){
                        prefix.push_back(ch);
                        printSuggestions(next, temp, prefix);
                        prefix.pop_back();
                    }
                }
                
            }
            
            vector<vector<string>> getSuggestions(string s){
                
                TrieNode* prev = root;
                vector<vector<string>> ans;
                string prefix = "";
                
                for(int i=0; i<s.length(); i++){
                    prefix += s[i];
                    
                    // check for the last character
                    TrieNode* curr = prev->children[s[i] - 'a'];
                    
                    if(curr == NULL){
                        break;
                    }
                    else{
                        vector<string> temp;
                        printSuggestions(curr, temp, prefix);
                        
                        ans.push_back(temp);
                        temp.clear();
                        
                        prev = curr;
                    }
                }
                
                return ans;
                
            }
    };
    
    
    
    

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        // create trie
        Trie* t = new Trie();
        
        // insert all the strings
        for(int i=0; i<n; i++){
            
            t->insert(contact[i]);
            
        }
        vector<vector<string>> ans = t->getSuggestions(s);
        if(ans.size() == s.size()) return ans;
        else{
            int diff = s.size() - ans.size();
            for(int i=0; i<diff; i++){
                ans.push_back({"0"});
            }
            return ans;
        }
    }
        
    };
