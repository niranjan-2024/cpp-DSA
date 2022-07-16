//Recursive Solution
class Solution {
public:
    
    int solve(string s,string t,int i,int j){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        
        
        if(s[i]==t[j]){
            return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
        }
        else{
            return solve(s,t,i-1,j);
        }
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return solve(s,t,n-1,m-1);
    }
};



//Recursion+Memoization
class Solution {
public:
    
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            dp[i][j] = solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
        }
        else{
            dp[i][j] = solve(s,t,i-1,j,dp);
        }
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};




//Tabulation
class Solution {
public:
    int Mod = 1e9+7;
    int solve(string &s,string &t,int n,int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                     dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%Mod;
                  }
                else{
                     dp[i][j] = dp[i-1][j];
                  }
            }
        }
        
        
        return dp[n][m];
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        return solve(s,t,n,m);
    }
};




//improved space Optimization
class Solution {
public:
    int Mod = 1e9+7;
    int solve(string &s,string &t,int n,int m){
        vector<int> prev(m+1,0);
        prev[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                     prev[j] = (prev[j-1]+prev[j])%Mod;
                  }
             }
        }
        
        return prev[m];
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        return solve(s,t,n,m);
    }
};
