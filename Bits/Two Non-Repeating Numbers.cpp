class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> v;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                i++;
            }
            else{
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};
