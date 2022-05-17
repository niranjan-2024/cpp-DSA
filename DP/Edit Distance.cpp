class Solution {
  public:
    int editDistance(string s, string t) {
        
        int m = s.size();
        int n = t.size();
        
        int EditD[m+1][n+1] = {};
        
        for(int i=0;i<=n;i++){
            EditD[0][i] = i;
        }
        for(int i=0;i<=m;i++){
            EditD[i][0] = i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    EditD[i][j] = EditD[i-1][j-1];
                }
                else{
                    EditD[i][j] = 1 + min(EditD[i-1][j-1],min(EditD[i-1][j],EditD[i][j-1]));
                }
            }
        }
        return EditD[m][n];
        
    }
};
