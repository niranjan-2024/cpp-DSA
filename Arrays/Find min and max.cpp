pair<long long, long long> getMinMax(long long a[], int n) {
    int maxi = a[0];
    int mini = a[0];
    
    for(int i=0;i<n;i++){
        if(a[i]<mini){
            mini = a[i];
        }
        if(a[i]>maxi){
            maxi = a[i];
        }
    }
    return {mini,maxi};
}
