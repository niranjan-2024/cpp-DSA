//Recursive
int helper(int n,vector<int> &nums)
    {
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];
        int take=helper(n-2,nums)+nums[n];
        int notake=helper(n-1,nums);
        return max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper(n-1,nums);
    }



//Memoization
int helper(int n,vector<int> &nums,vector<int> &arr)
    {
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];
        if(arr[n]!=-1)
            return arr[n];
        int take=helper(n-2,nums,arr)+nums[n];
        int notake=helper(n-1,nums,arr);
        arr[n]=max(notake,take);
        return arr[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+1,-1);
        return helper(n-1,nums,arr);
    }



//DP Space Optimization
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        arr[0]=nums[0];
        for(int i=1;i<n;++i){
            int take=nums[i];
            if(i>1)
                take+=arr[i-2];
            int notake=arr[i-1];
            arr[i]=max(take,notake);
        }
        return arr[n-1];
    }
