//Recursive solution
class Solution
{
    public:
    
    int solve(int n, int x, int y, int z){
        if(n==0){
            return 0;
        }
        if(n<0){
            INT_MIN;
        }
        
        int a = 1+solve(n-x,x,y,z);
        int b = 1+solve(n-y,x,y,z);
        int c = 1+solve(n-z,x,y,z);
        
        return max(a,max(b,c));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = solve(n,x,y,z);
        if(ans<0){
            return 0;
        }
        else{
            return ans;
        }
    }
};



//Top down approach ------ Recursion+memoization
class Solution
{
    public:
    
    int solve(int n, int x, int y, int z, vector<int> &dp){
       if(n == 0){
          return 0;
       }
       if(n < 0){
           return INT_MIN;
       }
       
       if(dp[n]!=-1) {
           return dp[n];
       }
       
       int a = solve(n-x, x, y, z, dp);
       int b = solve(n-y, x, y, z, dp);
       int c = solve(n-z, x, y, z, dp);
       
       dp[n] = 1 + max(max(a, b), c);
       return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = solve(n,x,y,z,dp);
        if(ans<0){
            return 0;
        }
        else{
            return ans;
        }
    }
};




//Bottom up ------ Tabulation
class Solution
{
    public:
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        
        dp[0] = 0;
        
        for(int i=1;i<=n;i++){
            if(i-x>=0 && dp[i-x]!=-1){
                dp[i] = max(dp[i],dp[i-x]+1);
            }
            if(i-y>=0 && dp[i-y]!=-1){
                dp[i] = max(dp[i],dp[i-y]+1);
            }
            if(i-z>=0 && dp[i-z]!=-1){
                dp[i] = max(dp[i],dp[i-z]+1);
            }
        }
        
        if(dp[n]<0){
            return 0;
        }
        else{
            return dp[n];
        }
    }
};



//SPACE OPTIMIZATION is not possible because lenght will depends on x,y,z unknowns
