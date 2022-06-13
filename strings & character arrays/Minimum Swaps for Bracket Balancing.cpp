class Solution{   
public:
       int minimumNumberOfSwaps(string S){
        int swap=0,x=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='['){
                x--;
            }else{
                x++;
                if(x>0){
                    swap+=x;
                }
            }
        }
        return swap;
    }
};
