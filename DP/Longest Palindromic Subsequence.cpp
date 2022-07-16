//Recursive solution
class Solution {
public:
    
    int solve(string &s,int left,int right){
        if(left>right){
            return 0;
        }
        if(left==right){
            return 1;
        }
        
        if(s[left]==s[right]){
            return 2+solve(s,left+1,right-1);
        }
        else{
            return max(solve(s,left+1,right),solve(s,left,right-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        return solve(s,0,n-1);
    }
};


//Recursion+Memoization
class Solution {
public:
    
    int solve(string &s,int left,int right,vector<vector<int>> &dp){
        if(left>right){
            return 0;
        }
        if(left==right){
            return 1;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s[left]==s[right]){
            dp[left][right] = 2+solve(s,left+1,right-1,dp);
        }
        else{
            dp[left][right] = max(solve(s,left+1,right,dp),solve(s,left,right-1,dp));
        }
        return dp[left][right];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};



//Tabulation
// it is similar to lowest common subsequence that if we reverese the give string and find LCS of original
//and reverse then it will be the longeest palindromic subsequence
class Solution {
public:
    
    int solve(string &s,int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string r = s;
        reverse(r.begin(),r.end());
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n<2){
            return n;
        }
        return solve(s,n);
    }
};
