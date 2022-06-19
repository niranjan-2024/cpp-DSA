class Solution{
public:
    int maxLength(string S){
        int open = 0 , close = 0;
        int max_len = 0;
        
        for(int i=0;i<S.size();i++){
            if(S[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                int len = open+close;
                max_len = max(max_len,len);
            }
            else if(close>open){
                open = close = 0;
            }
        }
        open = close = 0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                int len = open+close;
                max_len = max(max_len,len);
            }
            else if(open>close){
                open = close = 0;
            }
        }
        return max_len;
    }
};
