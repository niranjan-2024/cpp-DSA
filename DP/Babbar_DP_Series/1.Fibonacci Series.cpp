// Recursive Solution
int fibonaaci(int n){
  if(n==1||n==0){
    return n;
  }
  return fibonaaci(n-1)+fibonaaci(n-2);
}



// Top-Down --- (Recursive+Memoization) Solution
class Solution {
  public:
  
  long long int fibonaaci(long long int n,vector<long long int> &dp){
  if(n<=1){
    return n;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  dp[n] = fibonaaci(n-1,dp)+fibonaaci(n-2,dp);
  return dp[n]%1000000007;
}
  
    long long int nthFibonacci(long long int n){
      vector<long long int> dp(n+1);
      for(int i=0;i<=n;i++){
        dp[i]=-1;
       }
      
      return fibonaaci(n,dp);
    }
};




//Bottom up ---- Tabulation 
class Solution {
  public:
  
    long long int nthFibonacci(long long int n){
      vector<long long int> dp(n+1);
      dp[0] = 0;
      dp[1] = 1;
      
      for(long long int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
       }
      return dp[n];
    }
};



//Space Optimization
class Solution {
  public:
  
    long long int nthFibonacci(long long int n){
      long long int prev1 = 1;
      long long int prev2 = 0;
      if(n==0){
          return prev2;
      }
      
      for(long long int i=2;i<=n;i++){
        long long int curr=prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
       }
      return prev1;
    }
};
