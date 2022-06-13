class Solution {
public:
    
    bool ispalindrome(string str){
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    int minChar(string str){
        int i=0;
        int count=0;
        while(i<str.length()){
            if(ispalindrome(str.substr(0,i+1))){
                count = max(count,i+1);
            }
            i++;
        }
        return str.size()-count;
    }
};
