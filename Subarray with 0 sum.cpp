class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
       unordered_set<int>umap;
       int sum=0;
       for(int i=0;i<n;i++){
           if(arr[i]==0) return true;
           sum=sum+arr[i];
           if(umap.find(sum)!=umap.end() ||sum==0) return true;
          umap.insert(sum);
       }
       return false;
    }
};
