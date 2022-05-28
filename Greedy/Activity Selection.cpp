class Solution
{
    public:
    
   static bool mycomp(vector<int>& a, vector<int>& b) {
       return a[1] < b[1];
   }
   
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
       vector<vector<int>> act;
       
       for(int i=0;i<n;i++) 
           {act.push_back({start[i] , end[i]});}
           
       sort(act.begin(),act.end(), mycomp);
       
       int ans = 1,i=0;
       for(int j=1;j<n;j++) {
           {
               if(act[j][0] > act[i][1]) {
                  ans++;
                  i=j;
                }
           }
       }
       return ans;
    }
};
