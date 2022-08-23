//Recursive solution
class Solution {
  public:
  
    long long solve(int dice,int faces,int target){
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(target==0 && dice==0){
            return 1;
        }
        
        long long ans = 0;
        
        for(int i=1;i<=faces;i++){
            ans = ans+ solve(dice-1,faces,target-i);
        }
        return ans;
    }
  
    long long noOfWays(int M , int N , int X) {
        return solve(N,M,X);
    }
};



//Recursive + Memoization
class Solution {
  public:
  
    long long solve(int dice,int faces,int target,vector<vector<long long>> &dp){
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(target==0 && dice==0){
            return 1;
        }
        if(dp[dice][target]!=-1){
            return dp[dice][target];
        }
        
        long long ans = 0;
        
        for(int i=1;i<=faces;i++){
            ans = ans+ solve(dice-1,faces,target-i,dp);
        }
        
        return dp[dice][target] = ans;
    }
  
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return solve(N,M,X,dp);
    }
};



//Tabulation
class Solution {
  public:
  
    long long solve(int N,int faces,int X){
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,0));
        
        dp[0][0] = 1;
        
        for(int dice=1;dice<=N;dice++){
            for(int target=1;target<=X;target++){
                long long ans = 0;
                for(int i=1;i<=faces;i++){
                    if(target-i>=0){
                        ans = ans+ dp[dice-1][target-i];
                    }
                }
                 dp[dice][target] = ans;
            }
        }
        return dp[N][X];
    }
  
    long long noOfWays(int M , int N , int X) {
        return solve(N,M,X);
    }
};



//Space Optimization
class Solution {
  public:
  
    long long solve(int N,int faces,int X){
        vector<long long> curr(X+1,0);
        vector<long long> prev(X+1,0);
        
        prev[0] = 1;
        
        for(int dice=1;dice<=N;dice++){
            for(int target=1;target<=X;target++){
                long long ans = 0;
                for(int i=1;i<=faces;i++){
                    if(target-i>=0){
                        ans = ans+ prev[target-i];
                    }
                }
                 curr[target] = ans;
            }
            prev = curr;
        }
        return prev[X];
    }
  
    long long noOfWays(int M , int N , int X) {
        return solve(N,M,X);
    }
};
