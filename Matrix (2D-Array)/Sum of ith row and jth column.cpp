class Solution {
  public:
    int sumOfRowCol(int N, int M, vector<vector<int>> A) {
        int l=min(N,M);
        for(int i=0;i<l;i++){
            int sum1=0,sum2=0;
            for(int j=0;j<M;j++) sum1+=A[i][j];
            for(int j=0;j<N;j++) sum2+=A[j][i];
            if(sum1!=sum2) return 0;
        }
        return 1;
    }
};
