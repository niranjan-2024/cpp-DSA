class Solution{
    public:
    
    int fun(int n, int check)
    {
        return (n)*pow(2,n-1) + check*(pow(2,n));
    }
    
    int countSetBits(int n)
    {
        vector<int> v;
        while(n){
            v.push_back(n&1);
            n = n>>1;
        }
        int ans = 0;
        int check = 0;
        
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==1)
            {
                ans+= fun(i,check);
                check++;
                ans++;
            }
        }
        return ans;
    }
};
