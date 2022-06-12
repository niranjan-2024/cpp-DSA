class Solution{
public:
    bool check(string s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                return true;
            }
        }
        return false;
    }

    void removeDuplicate(string &s,int i){
        if(s.size()<=1){
         return;
        }
        while(i<s.size()){
            if(s[i]!=s[i+1]){
                i++;
            }
            else{
                int j=i;
                while(j+1<s.size() && s[j]==s[j+1]){
                    j++;
                }
                s.erase(s.begin()+i,s.begin()+j+1);
            }
        }
        if(check(s)==true){
            removeDuplicate(s,0);
        }
        return;
    }
    
    string rremove(string s){
        removeDuplicate(s,0);
        return s;
    }
};
