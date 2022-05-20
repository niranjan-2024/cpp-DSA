class Solution{
  public:
    int cutRod(int price[], int n) {
        int maxvalues[n+1];
        maxvalues[0] = 0;
        int i,j;
        for(i=1;i<=n;i++){
            maxvalues[i] = INT_MIN;
            for(j=0;j<i;j++){
                maxvalues[i] = max(maxvalues[i],price[j]+maxvalues[i-j-1]);
            }
        }
        return maxvalues[n];
    }
};
