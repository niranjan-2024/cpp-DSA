//Recursive 
class Solution {
public:
    
    int solve(int index,int difference,vector<int> &nums){
        if(index<0){
            return 0;
        }
        
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(nums[index]-nums[j]==difference){
                ans = max(ans,1+solve(j,difference,nums));
            }
        }
        return ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return n;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+solve(i,nums[j]-nums[i],nums));
            }
        }
        return ans;
    }
};



//Memoization
class Solution {
public:
    
    int solve(int index,int difference,vector<int> &nums,unordered_map<int,int> dp[]){
        if(index<0){
            return 0;
        }
        
        if(dp[index].count(difference)){
            return dp[index][difference];
        }
        
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(nums[index]-nums[j]==difference){
                ans = max(ans,1+solve(j,difference,nums,dp));
            }
        }
        return dp[index][difference] = ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return n;
        }
        
        unordered_map<int,int> dp[n+1];
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+solve(i,nums[j]-nums[i],nums,dp));
            }
        }
        return ans;
    }
};



//Tabulation
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        
        unordered_map<int,int> dp[n+1];
        
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                int cnt = 1;
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1+cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
