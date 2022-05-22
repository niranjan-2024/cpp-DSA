class Solution{
    public:
    int DivisibleByEight(string s){
         int n =s.size();
        if(n<3)
        {
            int r= atoi(s.c_str());
            if(r%8==0)
            {
                return 1;
            }
            return -1;
        }
        string t="";
        t=t+s[n-3]+s[n-2]+s[n-1];
       
        int j= atoi(t.c_str());
        if(j%8==0)
        {
            return 1;
        }
        return -1;
    }
};
