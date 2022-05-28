class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long count = a[m-1] - a[0];
        int j=1;
        for(int i=m;i<n;i++){
            if(a[i]-a[j]<count){
                count = a[i] - a[j];
            }
            j++;
        }
        return count;
    }   
};
