class Solution{
    public:
    
    void heapify(vector<int> &ans,int n,int i){
        int max=i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<n && ans[max]<ans[left]){
            max = left;
        }
        if(right<n && ans[max]<ans[right]){
            max = right;
        }
        
        if(max!=i){
            swap(ans[max],ans[i]);
            heapify(ans,n,max);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        int size = ans.size();
        
        for(int i=(size/2)-1;i>=0;i--){
            heapify(ans,size,i);
        }
        return ans;
    }
};
