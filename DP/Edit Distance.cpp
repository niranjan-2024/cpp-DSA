//Recursive Solution
class Solution {
public:
    
    int solve(string word1,string word2,int i,int j){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(word1[i]==word2[j]){
            return solve(word1,word2,i-1,j-1);
        }
        else{
            return 1+min(solve(word1,word2,i-1,j-1),min(solve(word1,word2,i,j-1),solve(word1,word2,i-1,j)));
        }
        
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return solve(word1,word2,n1-1,n2-1);
    }
};



//Recursion+Memoization
class Solution {
public:
    
    int solve(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 0;
        
        if(word1[i]==word2[j]){
            ans = solve(word1,word2,i-1,j-1,dp);
        }
        else{
            ans = 1+min(solve(word1,word2,i-1,j-1,dp),min(solve(word1,word2,i,j-1,dp),solve(word1,word2,i-1,j,dp)));
        }
        dp[i][j] = ans;
        return ans;
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(word1,word2,n1-1,n2-1,dp);
    }
};




//Tabulation - Bottom up 
class Solution {
public:
    
    int solve(string word1,string word2,int n1,int n2){
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=0;i<=n1;i++){
            dp[i][0] = i;
        }
        
        for(int j=0;j<=n2;j++){
            dp[0][j] = j;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 0+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return solve(word1,word2,n1,n2);
    }
};




//Space optimization
class Solution {
public:
    
    int solve(string word1,string word2,int n1,int n2){
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        
        for(int j=0;j<=n2;j++){
            prev[j] = j;
        }
        
        for(int i=1;i<=n1;i++){
            curr[0] = i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = 0+prev[j-1];
                }
                else{
                    curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return solve(word1,word2,n1,n2);
    }
};
