class Solution {
public:
    int dp[500][2000];
    
    int solve(int i,int remain,vector<int> nums,int k){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][remain]!=-1){
            return dp[i][remain];
        }
        int ans = 0 , choice1 = 0 , choice2 = 0;
        if(nums[i]>remain){
            ans = (remain+1)*(remain+1) + solve(i+1,k-nums[i]-1,nums,k);
        }
        else{
            choice1 = (remain+1)*(remain+1) + solve(i+1,k-nums[i]-1,nums,k);
            choice2 = solve(i+1,remain-nums[i]-1,nums,k);
            ans = min(choice1,choice2);
        }
        dp[i][remain] = ans;
        return ans;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(0,k,nums,k);
    } 
};
