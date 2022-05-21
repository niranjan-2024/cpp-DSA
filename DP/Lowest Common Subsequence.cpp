class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int LCScount[x+1][y+1];
        
        for(int i=0;i<=x; i++){
            LCScount[i][0] = 0;
        }
        for(int j=0;j<=y;j++){
            LCScount[0][j] = 0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    LCScount[i][j] = LCScount[i-1][j-1] + 1;
                }
                else{
                    LCScount[i][j] = max(LCScount[i-1][j],LCScount[i][j-1]);
                }
            }
        }
        return LCScount[x][y];
    }
};
