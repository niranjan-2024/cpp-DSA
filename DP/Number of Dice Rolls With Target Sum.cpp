//Recursive Solution
class Solution {
public:
    
    int solve(int dice,int faces,int target){
        if(target<0){
            return 0;
        }
        if(target!=0 && dice==0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(target==0 && dice==0){
            return 1;
        }
        
        int result = 0;
        for(int i=1;i<=faces;i++){
            result = result + solve(dice-1,faces,target-i);
        }
        return result;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};




//Recursion+Memoization
class Solution {
public:
    
    int solve(int dice,int faces,int target,vector<vector<int>> &dp){
        if(target<0){
            return 0;
        }
        if(target!=0 && dice==0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(target==0 && dice==0){
            return 1;
        }
        if(dp[target][dice]!=-1){
            return dp[target][dice];
        }
        int result = 0;
        for(int i=1;i<=faces;i++){
            result = (result + solve(dice-1,faces,target-i,dp))%1000000007;
        }
        dp[target][dice] = result;
        return dp[target][dice];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return solve(n,k,target,dp);
    }
};




//Tabulation
