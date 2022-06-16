class Solution {
  public:
    int romanToDecimal(string &str) {
        int sum = 0;
        map<char,int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        for(int i=0;i<str.length();i++){
            if(i!=0 && hash[str[i]]>hash[str[i-1]]){
                sum = sum + hash[str[i]];
                sum = sum - 2*(hash[str[i-1]]);
            }
            else{
                sum = sum + hash[str[i]];
            }
        }
        return sum;
    }
};
