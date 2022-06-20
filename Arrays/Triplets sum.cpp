class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int X)
    {
        sort(a,a+n); 
       int l,r;
       for(int i=0;i<n-2;i++)
       {
           l = i+1;
           r = n-1;
           while(l<r)
           {
           if(a[i] + a[l] + a[r] == X)
             return true;
            if(a[i] + a[l] + a[r]<X)
             l++;
            else
             r--;
           }
       }
       return false;
    }

};
