class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long p = 1;
	    long long ans = INT_MIN;
	    for(int i=0;i<n;i++){
	        p*= arr[i];
	        ans = max(p,ans);
	        if(p==0){
	            p=1;
	        }
	    }
	    p=1;
	    for(int i=n-1;i>=0;i--){
	        p*= arr[i];
	        ans = max(p,ans);
	        if(p==0){
	            p=1;
	        }
	    }
	    if(ans == INT_MIN) return -1;
	    return ans;
	}
};
