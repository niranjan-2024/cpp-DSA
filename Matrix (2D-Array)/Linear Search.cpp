int matSearch (int N, int M, int matrix[][M], int x)
{
    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            if(matrix[row][col]==x){
                return 1;
            }
        }
    }
    return 0;
}
