class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    for(int i=0;i<n-1;i++){
	        if(arr[i]>arr[i+1] && i%2==0) swap(arr[i],arr[i+1]);
	        if(arr[i]<arr[i+1] && i%2==1) swap(arr[i],arr[i+1]);
	    }
	}
};
