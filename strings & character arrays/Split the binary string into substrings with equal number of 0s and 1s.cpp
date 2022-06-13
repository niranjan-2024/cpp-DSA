class Solution {
public:
    int maxSubStr(string str){
        int cz=0,count=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                cz++;
            }
            else{
                cz--;
            }
            if(cz==0){
                count++;
            }
        }
        if(cz==0){
            return count;
        }
        return -1;
    }
};
