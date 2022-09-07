class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //creating a min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        
      //putting k largest elements in heap
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
      //returning kth largest
        return pq.top();
    }
};

// similarly in the case of kth smallest element use max heap and reverse condition
