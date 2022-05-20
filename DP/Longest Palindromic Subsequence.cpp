class Solution{
  public:
    int longestPalinSubseq(string S) {
        int n = S.length();
        if(n<=0){
            return 0;
        }
        int table[n][n];
        
        for(int i=0;i<n;i++){
            table[i][i] = 1;
        }
        
        for(int k=2;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j =i+k-1;
                if(S[i]==S[j] && k==2){
                    table[i][j] = 2;
                }
                else if(S[i] == S[j]){
                    table[i][j] = table[i+1][j-1] + 2;
                }
                else{
                    table[i][j] = max(table[i+1][j],table[i][j-1]);
                }
            }
        }
        return table[0][n-1];
    }
};
