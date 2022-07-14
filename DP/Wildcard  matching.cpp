//Recursive Solution
class Solution {
public:
    
    bool isAllStars(string &p,int j){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    
    bool solve(string &s,string &p,int i,int j){
        if(i<0 && j<0){
            return true;
        }
        if(j<0 && i>=0){
            return false;
        }
        if(i<0 && j>=0){
            return isAllStars(p,j);
        }
        
        
        if((s[i]==p[j])||(p[j]=='?')){
            return solve(s,p,i-1,j-1);
        }
        else{
            if(p[j]=='*'){
                return solve(s,p,i-1,j)||solve(s,p,i,j-1);
            }
            else{
                return false;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        return solve(s,p,n-1,m-1);
    }
};




//Recursion + Memoization
class Solution {
public:
    
    bool isAllStars(string &p,int j){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(j<0 && i>=0){
            return false;
        }
        if(i<0 && j>=0){
            return isAllStars(p,j);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if((s[i]==p[j])||(p[j]=='?')){
            dp[i][j] = solve(s,p,i-1,j-1,dp);
        }
        else{
            if(p[j]=='*'){
                dp[i][j] = solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
            }
            else{
                return false;
            }
        }
        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(s,p,n-1,m-1,dp);
    }
};




//Tabulation
class Solution {
public:
    
    bool isAllStars(string &p,int j){
        for(int k=1;k<=j;k++){
            if(p[k-1]!='*'){
                return false;
            }
        }
        return true;
    }
    
    bool solve(string &s,string &p,int n,int m){
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = isAllStars(p,j);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((s[i-1]==p[j-1])||(p[j-1]=='?')){
                    dp[i][j] = dp[i-1][j-1];
                   }        
                else{
                    if(p[j-1]=='*'){
                        dp[i][j] = dp[i-1][j]||dp[i][j-1];
                     }
                    else{
                        dp[i][j] = false;
                     }
                   }
             }
        }
        
        
        return dp[n][m];
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        return solve(s,p,n,m);
    }
};




//Space Optimization(little bit changed)
class Solution {
public:
    
    bool isAllStars(string &s,int i){
        for(int k=1;k<=i;k++){
            if(s[k-1]!='*'){
                return false;
            }
        }
        return true;
    }
    
    bool solve(string &p,string &s){
        
        int n = p.size();
        int m = s.size();

        vector < bool > prev(m + 1, false);
        vector < bool > cur(m + 1, false);

        prev[0] = true;

        for (int i = 1; i <= n; i++) {
             cur[0] = isAllStars(p, i);
             for (int j = 1; j <= m; j++) {

                  if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                      cur[j] = prev[j - 1];

                  else {
                      if (p[i - 1] == '*')
                          cur[j] = prev[j] || cur[j - 1];

                      else cur[j] = false;
                       }
                 }
           prev = cur;
          }

         return prev[m];
    }
    
    bool isMatch(string s, string p) {
        return solve(p,s);
    }
};
