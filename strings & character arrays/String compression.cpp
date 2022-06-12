class Solution {
public:
    int compress(vector<char>& str) {
     int i=0;
    int ansIndex=0;
    while(i<str.size()){
        int j=i+1;
        while(j<str.size() && str[i]==str[j]){
            j++;
        }
        str[ansIndex++]=str[i];
        int count=j-i;
        if(count>1){
            string s=to_string(count);
            for(char ch: s){
                str[ansIndex++]=ch;
            }
        }
        i=j;
    }
    return ansIndex;
    }
};
