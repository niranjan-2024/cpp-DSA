class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int row = n;
        int col = m;
        
        int rowindex = 0;
        int colindex = col-1;
        
        while(rowindex<row && colindex>=0){
            int element = matrix[rowindex][colindex];
            if(element==x){
                return 1;
            }
            if(element<x){
                rowindex++;
            }
            else{
                colindex--;
            }
        }
        return 0;
    }
};
