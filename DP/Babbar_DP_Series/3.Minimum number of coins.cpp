//Recursion Solution
class Solution {
public:
    
    int solve(vector<int> &coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};




//recursion+memoization ---- top down
class Solution {
public:
    
    int solve(vector<int> &coins,int amount,vector<int> &dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i],dp);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = solve(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }    
        else{
            return ans;
        }
    }
};




//Bottom up ----- Tabulation
class Solution {
public:
    
    int solve(vector<int> &coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++){
            
            for(int j=0;j<coins.size();j++){
                
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins,amount);
    }
};




//SPACE OPTIMIZATION IS NOT POSSIBLE ---- IF WE TRY TO OPTIMIZE THEN WE WILL AGAIN USE THAT
