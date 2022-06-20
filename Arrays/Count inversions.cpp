class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans = 0;
    
    void merge(long long arr[],long long l,long long m,long long r){
        long long n1 = m-l+1;
        long long n2 = r-m;
        long long L[n1],R[n2];
        for(long long i=0;i<n1;i++){
            L[i] = arr[l+i];
        }
        for(long long i=0;i<n2;i++){
            R[i] = arr[m+1+i];
        }
        long long i = 0;
        long long j = 0;
        long long k = l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k++] = L[i];
                i++;
            }
            else{
                arr[k++] = R[j];
                ans+=(n1-i);
                j++;
            }
        }
        while(i<n1){
            arr[k++] = L[i++];
        }
        while(j<n2){
            arr[k++] = R[j++];
        }
    }
    
    void mergesort(long long arr[],long long l,long long r){
        if(l<r){
            long long m = (l+r)/2;
            mergesort(arr,l,m);
            mergesort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergesort(arr,0,N-1);
        return ans;
    }

};
