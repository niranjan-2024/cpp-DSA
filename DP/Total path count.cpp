class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        long long int dp[m][n];
        
        for(long long int i=1;i<m;i++){
            dp[i][0] = 1;
        }
        for(long long int i=1;i<n;i++){
            dp[0][i] = 1;
        }
            for(long long int i=1;i<m;i++){
                for(long long int j=1;j<n;j++){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
                }
            }
        return dp[m-1][n-1];
    }
};
