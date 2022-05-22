class Solution {
  public:
    int binary_to_decimal(string str) {
        int n = str.size();
        int ans = 0;
        int count = 0;
        for(int i = n-1;i>=0;i--){
            ans = ((str[i] -'0')*pow(2,count)) + ans;
            count++;
        }
        return ans;
    }
};
