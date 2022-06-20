class Solution{
public:

	void rearrange(int arr[], int n) {
	     vector<int> pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0) neg.push_back(arr[i]);
	        else pos.push_back(arr[i]);
	    }
	    int i=0,j=0,k=0;
	    int len1 = pos.size();
	    int len2 = neg.size();
	    while(k<n){
	        if(i<len1) arr[k++] = pos[i++];
	        if(k<n){
	            if(j<len2) arr[k++] = neg[j++];
	        }
	    }
	}
};
