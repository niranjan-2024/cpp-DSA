//Recursive solution
class Solution {
public:
    
    int solve(vector<int> &prices,int buy,int index,int n,int fee){
        if(index==n){
            return 0;
        }
            int profit = 0;
            
            if(buy==0){
                profit = max(0+solve(prices,0,index+1,n,fee),-prices[index]+solve(prices,1,index+1,n,fee));
            }
            if(buy==1){
                profit = max(0+solve(prices,1,index+1,n,fee),prices[index] - fee+solve(prices,0,index+1,n,fee));
            }
            
            return profit;
            
        }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return solve(prices,0,0,n,fee);
    }
};


//Recursion+Memoization
class Solution {
public:
    
    int solve(vector<int> &prices,int buy,int index,int n,vector<vector<int>> &dp,int fee){
        if(index==n){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        int profit = 0;
            
        if(buy==0){
            profit = max(0+solve(prices,0,index+1,n,dp,fee),-prices[index]+solve(prices,1,index+1,n,dp,fee));
        }
        if(buy==1){
             profit = max(0+solve(prices,1,index+1,n,dp,fee),prices[index] - fee+solve(prices,0,index+1,n,dp,fee));
        }
            
        dp[index][buy] = profit;
        return dp[index][buy];
            
        }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices, 0 , 0, n,dp,fee);
    }
};


//Tabulation
class Solution {
public:
    
    int solve(vector<int> &prices,int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+dp[index+1][0],-prices[index]+dp[index+1][1]);
                   }
                if(buy==1){
                     profit = max(0+dp[index+1][1],prices[index]-fee+dp[index+1][0]);
                   }
                dp[index][buy] = profit;
            }
        }
        
            
        
        return dp[0][0];
            
        }
    
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices,fee);
    }
};



//Space Optimization
class Solution {
public:
    
    int solve(vector<int> &prices,int fee){
        int n = prices.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        
        next[0] = 0;
        next[1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+next[0],-prices[index]+next[1]);
                   }
                if(buy==1){
                     profit = max(0+next[1],prices[index]-fee+next[0]);
                   }
                curr[buy] = profit;
            }
            next = curr;
        }
        
                  
        return curr[0];
            
        }
    
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices,fee);
    }
};



//Improved space optimization
class Solution {
public:
    
    int solve(vector<int> &prices,int fee){
        int n = prices.size();
        vector<int> curr(2,0);
        
        curr[0] = 0;
        curr[1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+curr[0],-prices[index]+curr[1]);
                   }
                if(buy==1){
                     profit = max(0+curr[1],prices[index]-fee+curr[0]);
                   }
                curr[buy] = profit;
            }
        }
        
                  
        return curr[0];
            
        }
    
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices,fee);
    }
};

