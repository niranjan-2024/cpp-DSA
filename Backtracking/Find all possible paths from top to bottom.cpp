class Solution
{
public:

     void helper(int n,int m, int i,int j,vector<vector<int>>&ans,vector<int>v,vector<vector<int>> &grid){
       if(i>=n or j>=m){
           return;
       }
       v.push_back(grid[i][j]);
       if(i==n-1 and j==m-1){
           ans.push_back(v);
           return;
       }
       helper(n,m,i+1,j,ans,v,grid);
       helper(n,m,i,j+1,ans,v,grid);
       
   }
   
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
       vector<vector<int>> ans;
       vector<int> v;
       helper(n,m,0,0,ans,v,grid);
       return ans;
    }
};
