//Recursive solution
class Solution{
    #define MOD 1000000007
    public:
    long long add(long long a,long long b){
        return (a%MOD + b%MOD)%MOD;
    }
    
    long long mul(long long a,long long b){
        return ((a%MOD)*1LL*(b%MOD))%MOD;
    }
    
    long long solve(int n,int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,mul(k,k-1));
        }
        
        int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
        return ans;
    }
    
    long long countWays(int n, int k){
        return solve(n,k);
    }
};




//Recursion + Memoization ---- Top-Down DP
class Solution{
    #define MOD 1000000007
    public:
    long long add(long long a,long long b){
        return (a%MOD + b%MOD)%MOD;
    }
    
    long long mul(long long a,long long b){
        return ((a%MOD)*1LL*(b%MOD))%MOD;
    }
    
    long long solve(int n,int k,vector<int> &dp){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,mul(k,k-1));
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
        return dp[n];
    }
    
    long long countWays(int n, int k){
        vector<int> dp(n+1,-1);
        return solve(n,k,dp);
    }
};



//Tabulation ---- Bottom UP
class Solution{
    #define MOD 1000000007
    public:
    long long add(long long a,long long b){
        return (a%MOD + b%MOD)%MOD;
    }
    
    long long mul(long long a,long long b){
        return ((a%MOD)*1LL*(b%MOD))%MOD;
    }
    
    long long solve(int n,int k){
        vector<int> dp(n+1,0);
        
        dp[1] = k;
        dp[2] = add(k,mul(k,k-1));
        
        for(int i=3;i<=n;i++){
            dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
        }
        
        return dp[n];
    }
    
    long long countWays(int n, int k){
        return solve(n,k);
    }
};




//Space Optimization
class Solution{
    #define MOD 1000000007
    public:
    long long add(long long a,long long b){
        return (a%MOD + b%MOD)%MOD;
    }
    
    long long mul(long long a,long long b){
        return ((a%MOD)*1LL*(b%MOD))%MOD;
    }
    
    long long solve(int n,int k){
        
        int prev2 = k;
        int prev1 = add(k,mul(k,k-1));
        
        if(n==1){
            return prev2;
        }
        
        for(int i=3;i<=n;i++){
            int curr = add(mul(prev2,k-1),mul(prev1,k-1));
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    long long countWays(int n, int k){
        return solve(n,k);
    }
};
