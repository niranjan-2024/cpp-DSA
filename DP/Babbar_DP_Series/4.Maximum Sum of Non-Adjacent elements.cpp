//Recursive Solution
class Solution{
public:	
	
	int solve(int *arr,int n){
	    if(n<0){
	        return 0;
	    }
	    if(n==0){
	        return arr[0];
	    }
	    
	    int include = solve(arr,n-2) + arr[n];
	    int exclude = solve(arr,n-1) + 0;
	    return max(include,exclude);
	}
	
	int findMaxSum(int *arr, int n) {
	    return solve(arr,n-1);
	}
};



//Recursion+memoization----Top Down 
class Solution{
public:	
	
	int solve(int *arr,int n,vector<int> &dp){
	    if(n<0){
	        return 0;
	    }
	    if(n==0){
	        return arr[0];
	    }
	    
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    
	    int include = solve(arr,n-2,dp) + arr[n];
	    int exclude = solve(arr,n-1,dp) + 0;
	    dp[n] = max(include,exclude);
	    return dp[n];
	}
	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1,-1);
	    return solve(arr,n-1,dp);
	}
};




//Bottom up-----Tabulation
class Solution{
public:	
	
	int solve(int *arr,int n){
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    
	    for(int i=1;i<n;i++){
	        int include = dp[i-2] + arr[i];
	        int exclude = dp[i-1] + 0;
	        dp[i] = max(exclude,include);
	    }
	    return dp[n-1];
	}
	
	int findMaxSum(int *arr, int n) {
	    return solve(arr,n);
	}
};




//Space optimization
class Solution{
public:	
	
	int solve(int *arr,int n){
	    int prev2 = 0;
	    int prev1 = arr[0];
	    
	    for(int i=1;i<n;i++){
	        int include = prev2 + arr[i];
	        int exclude = prev1 + 0;
	        int curr = max(exclude,include);
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    return prev1;
	}
	
	int findMaxSum(int *arr, int n) {
	    return solve(arr,n);
	}
};
