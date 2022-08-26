class Solution{
public:

    int solve(int arr[],int i,int j){
        if(i==j){
            return 0;
        }
        
        int ans = INT_MAX;
        //int mini;
        for(int k=i;k<j;k++){
            int mini =  solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            ans = min(mini,ans);
        }
        return ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,1,N-1);
    }
};




class Solution{
public:

    int solve(int arr[],int i,int j,vector<vector<int>> &dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int mini =  solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            ans = min(mini,ans);
        }
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return solve(arr,1,N-1,dp);
    }
};
