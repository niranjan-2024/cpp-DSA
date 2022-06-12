class Solution {
public:
    string convert(string input){
        string res;
        int i=0;int j=0;
        while(i<input.length()&&j<input.length()){
            int count=0;
            while(input[i]==input[j]){
                count++;
                j++;
            }
            res.push_back(count+'0');
            res.push_back(input[i]);
            i=j;
        }
        return res;
    }
    string countAndSay(int n) {
        if(n==1){
            string res="1";
            return res;
        }
        string temp_res=countAndSay(n-1);
        return convert(temp_res);
  }
};
