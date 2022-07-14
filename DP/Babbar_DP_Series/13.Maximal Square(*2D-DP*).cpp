//Recursive solution
class Solution{
public:

    int solve(vector<vector<int>> &mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int right = solve(mat,i,j+1,maxi);
        int diagonal = solve(mat,i+1,j+1,maxi);
        int left = solve(mat,i+1,j,maxi);
        
        if(mat[i][j]==1){
            int ans = 1+min(right,min(left,diagonal));
            maxi = max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        solve(mat,0,0,maxi);
        return maxi;
    }
};




//Recursion+Memoization(leetcode sol)
class Solution {
public:
    
    int solve(vector<vector<char>> &matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right = solve(matrix,i,j+1,maxi,dp);
        int diagonal = solve(matrix,i+1,j+1,maxi,dp);
        int left = solve(matrix,i+1,j,maxi,dp);
        
        if(matrix[i][j]=='1'){
            dp[i][j] = 1+min(right,min(left,diagonal));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 0;
        solve(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};



//Tabulation
class Solution {
public:
    
    int solve(vector<vector<char>> &matrix,int n,int m,int &maxi){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int left = dp[i+1][j];
        
                if(matrix[i][j]=='1'){
                   dp[i][j] = 1+min(right,min(left,diagonal));
                   maxi = max(maxi,dp[i][j]);
                  }
                else{
                   dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxi = 0;
        solve(matrix,n,m,maxi);
        return maxi*maxi;
    }
};



//Space Optimization
class Solution {
public:
    
    int solve(vector<vector<char>> &matrix,int n,int m,int &maxi){
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int left = next[j];
        
                if(matrix[i][j]=='1'){
                   curr[j] = 1+min(right,min(left,diagonal));
                   maxi = max(maxi,curr[j]);
                  }
                else{
                   curr[j] = 0;
                }
            }
            next = curr;
        }
        return curr[0];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxi = 0;
        solve(matrix,n,m,maxi);
        return maxi*maxi;
    }
};









