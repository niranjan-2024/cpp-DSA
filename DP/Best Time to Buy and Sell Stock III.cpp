//Recursive Solution
class Solution {
public:
    
    int solve(vector<int> &prices,int n,int index,int buy,int maxTransactions){
        if(index==n || maxTransactions == 0){
            return 0;
        }
        
        int profit = 0;
        
        if(buy==0){
            profit = max(0+solve(prices,n,index+1,0,maxTransactions),-prices[index] + solve(prices,n,index+1,1,maxTransactions));
        }
        
        if(buy==1){
            profit = max(0+solve(prices,n,index+1,1,maxTransactions),prices[index] + solve(prices,n,index+1,0,maxTransactions-1));
        }
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices,n,0,0,2);
    }
};




//Recursion+Memoization
class Solution {
public:
    
    int solve(vector<int> &prices,int n,int index,int buy,int maxTransactions,vector<vector<vector<int>>> &dp){
        if(index==n || maxTransactions == 0){
            return 0;
        }
        
        if(dp[index][buy][maxTransactions]!=-1){
            return dp[index][buy][maxTransactions];
        }
        
        int profit = 0;
        
        if(buy==0){
            profit = max(0+solve(prices,n,index+1,0,maxTransactions,dp),-prices[index] + solve(prices,n,index+1,1,maxTransactions,dp));
        }
        
        if(buy==1){
            profit = max(0+solve(prices,n,index+1,1,maxTransactions,dp),prices[index] + solve(prices,n,index+1,0,maxTransactions-1,dp));
        }
        
        dp[index][buy][maxTransactions] = profit;
        return dp[index][buy][maxTransactions];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,n,0,0,2,dp);
    }
};




//Tabulation
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int maxTransactions=1;maxTransactions<=2;maxTransactions++){
                    if(buy==0){
                       dp[index][buy][maxTransactions] = max(0+dp[index+1][0][maxTransactions],-prices[index] + dp[index+1][1][maxTransactions]);
                      }
        
                    if(buy==1){
                      dp[index][buy][maxTransactions] = max(0+dp[index+1][1][maxTransactions],prices[index] + dp[index+1][0][maxTransactions-1]);
                       }
                }
            }
        }
        
        return dp[0][0][2];
    }
    
    int maxProfit(vector<int>& prices) {
        
        return solve(prices);
    }
};





//Space Optimization
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int maxTransactions=1;maxTransactions<=2;maxTransactions++){
                    if(buy==0){
                       curr[buy][maxTransactions] = max(0+ahead[0][maxTransactions],-prices[index] + ahead[1][maxTransactions]);
                      }
        
                    if(buy==1){
                      curr[buy][maxTransactions] = max(0+ahead[1][maxTransactions],prices[index] + ahead[0][maxTransactions-1]);
                       }
                }
            }
            ahead = curr;
        }
        
        return curr[0][2];
    }
    
    int maxProfit(vector<int>& prices) {
        
        return solve(prices);
    }
};




//Improved space optimization
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        //vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int maxTransactions=1;maxTransactions<=2;maxTransactions++){
                    if(buy==0){
                       curr[buy][maxTransactions] = max(0+curr[0][maxTransactions],-prices[index] + curr[1][maxTransactions]);
                      }
        
                    if(buy==1){
                      curr[buy][maxTransactions] = max(0+curr[1][maxTransactions],prices[index] + curr[0][maxTransactions-1]);
                       }
                }
            }
            
        }
        
        return curr[0][2];
    }
    
    int maxProfit(vector<int>& prices) {
        
        return solve(prices);
    }
};
