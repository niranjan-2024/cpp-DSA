class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int table[n+1][W+1];
       
       for(int i=0;i<=n;i++){
           table[i][0] = 0;
       }
       for(int j=1;j<=W;j++){
           table[0][j] =0;
       }
       
       for(int i=1;i<=n;i++){
           for(int cp=1;cp<=W;cp++){
               if(wt[i-1]<=cp){
                   table[i][cp] = max(val[i-1]+table[i-1][cp-wt[i-1]],table[i-1][cp]);
               }
               else{
                   table[i][cp] = table[i-1][cp];
               }
           }
       }
       return table[n][W];
    }
};
