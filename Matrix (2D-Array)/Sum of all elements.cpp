class Solution {
  public:
    int sumOfMatrix(int N, int M, vector<vector<int>> Grid) {
        int sum=0;
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                sum+=Grid[row][col];
            }
        }
        return sum;
    }
};
