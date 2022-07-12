//Recursive Solution
class Solution {
public:
    
    int solve(int n,vector<int> &days,vector<int> &costs,int index){
        if(index>=n){
            return 0;
        }
        
        int option1 = costs[0] + solve(n,days,costs,index+1);
        
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++)
        {}
        int option2 = costs[1] + solve(n,days,costs,i);
        
        for(i=index;i<n && days[i]<days[index]+30;i++)
        {} 
        int option3 = costs[2] + solve(n,days,costs,i);
        
        int ans = min(option1,min(option2,option3));
        return ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n,days,costs,0);
    }
};




//Recursion + Memoization -----   Top Down DP
class Solution {
public:
    
    int solve(int n,vector<int> &days,vector<int> &costs,int index,vector<int> &dp){
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int option1 = costs[0] + solve(n,days,costs,index+1,dp);
        
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++)
        {}
        int option2 = costs[1] + solve(n,days,costs,i,dp);
        
        for(i=index;i<n && days[i]<days[index]+30;i++)
        {} 
        int option3 = costs[2] + solve(n,days,costs,i,dp);
        
        int ans = min(option1,min(option2,option3));
        dp[index] = ans;
        return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(n,days,costs,0,dp);
    }
};





//Tabulation ---- Bottom UP
class Solution {
public:
    
    int solve(int n,vector<int> &days,vector<int> &costs){
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        
      for(int k=n-1;k>=0;k--){
            
        int option1 = costs[0] + dp[k+1];
        
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++)
        {}
        int option2 = costs[1] + dp[i];
        
        for(i=k;i<n && days[i]<days[k]+30;i++)
        {} 
        int option3 = costs[2] + dp[i];
        
        int ans = min(option1,min(option2,option3));
        dp[k] = ans;
        }
      return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n,days,costs);
    }
};




//Space Optimization
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        
        for(int day : days){
            while(!month.empty() && month.front().first+30<=day){
                month.pop();
            }
            while(!week.empty() && week.front().first+7<=day){
                week.pop();
            }
            
            month.push(make_pair(day,ans+costs[2]));
            week.push(make_pair(day,ans+costs[1]));
            
            ans = min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
};
