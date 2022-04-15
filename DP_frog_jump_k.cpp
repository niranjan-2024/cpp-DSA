#include<bits/stdc++.h>
using namespace std;

int solveutil(int ind,vector<int>& height,vector<int>& dp,int k){
   if(ind == 0) return 0;
   if(dp[ind]!=-1) return dp[ind];
   int min_steps = INT_MAX;
   for(int i=1;i<=k;i++){
      if(ind-i>=0){
         int jump = solveutil(ind-i,height,dp,k) + abs(height[ind]-height[ind-i]);
         min_steps = min(jump,min_steps);
         
      }
   }
   return dp[ind] = min_steps;
}


int solve(int n, vector<int>& height,int k){
   vector<int> dp(n,-1);
   return solveutil(n-1,height,dp,k);
}

int main(){
   vector<int> height{30,10,60 , 10 , 60 , 50};
   int n = height.size();
   int k = 2;
   vector<int> dp(n,-1);
   cout<<solve(n,height,k);
   return 0;
}
