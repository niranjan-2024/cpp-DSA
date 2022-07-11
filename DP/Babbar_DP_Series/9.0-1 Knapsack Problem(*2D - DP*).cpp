//Recursion Solution
class Solution
{
    public:
    
    int solve(int wt[],int val[],int index,int capacity){
        if(index==0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        int include = 0;
        if(wt[index]<=capacity){
            include = val[index] + solve(wt,val,index-1,capacity - wt[index]);
        }
        int exclude = 0 + solve(wt,val,index-1,capacity);
        int ans = max(exclude,include);
        return ans;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solve(wt,val,n-1,W);
    }
};





//Recursion+Memoization -------  Top Down DP
class Solution
{
    public:
    
    int solve(int wt[],int val[],int index,int capacity,vector<vector<int>> &dp){
        if(index==0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][capacity]!=-1){
            return dp[index][capacity];
        }
        
        int include = 0;
        if(wt[index]<=capacity){
            include = val[index] + solve(wt,val,index-1,capacity - wt[index],dp);
        }
        int exclude = 0 + solve(wt,val,index-1,capacity,dp);
        dp[index][capacity] = max(exclude,include);
        return dp[index][capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(wt,val,n-1,W,dp);
    }
};




//Tabulation ------ Bottom UP DP
class Solution
{
    public:
    
    int solve(int wt[],int val[],int n,int capacity){
        vector<vector<int>> dp(n,vector<int> (capacity+1,0));
        
        for(int w = wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                dp[0][w] = val[0];
            }
            else{
                dp[0][w] = 0;
            }
        }
        
        for(int index=1;index<n;index++){
            for(int w=0;w<=capacity;w++){
                int include = 0;
                if(wt[index]<=w){
                    include = val[index] + dp[index-1][w-wt[index]];
                }
                int exclude = 0 + dp[index-1][w];
                dp[index][w] = max(exclude,include);
            }
        }
        return dp[n-1][capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        return solve(wt,val,n,W);
    }
};






//Space Optimization
class Solution
{
    public:
    
    int solve(int wt[],int val[],int n,int capacity){
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
        
        for(int w = wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                prev[w] = val[0];
            }
            else{
                prev[w] = 0;
            }
        }
        
        for(int index=1;index<n;index++){
            for(int w=0;w<=capacity;w++){
                int include = 0;
                if(wt[index]<=w){
                    include = val[index] + prev[w-wt[index]];
                }
                int exclude = 0 + prev[w];
                curr[w] = max(exclude,include);
            }
            prev = curr;
        }
        return prev[capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        return solve(wt,val,n,W);
    }
};





//Improved Space Optimization
class Solution
{
    public:
    
    int solve(int wt[],int val[],int n,int capacity){
        vector<int> curr(capacity+1,0);
        
        for(int w = wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                curr[w] = val[0];
            }
            else{
                curr[w] = 0;
            }
        }
        
        for(int index=1;index<n;index++){
            for(int w=capacity;w>=0;w--){
                int include = 0;
                if(wt[index]<=w){
                    include = val[index] + curr[w-wt[index]];
                }
                int exclude = 0 + curr[w];
                curr[w] = max(exclude,include);
            }
        }
        return curr[capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        return solve(wt,val,n,W);
    }
};
