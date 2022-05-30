class Solution{
public:
   vector<vector<int>> ans;
   
   bool isSafe(int row, int col, int n, vector<vector<int>> &board){
       for(int i=0;i<col;i++){
           if(board[row][i]==1) return false;
       }
       for(int i=row,j=col; i>=0 && j>=0; i--,j--){
           if(board[i][j]==1) return false;
       }
       for(int i=row,j=col;i<n && j>=0;i++,j--){
           if(board[i][j]==1) return false;
       }
       return true;
   }
  
   void solveRec(int col, int n, vector<vector<int>> &board, vector<int> &cases){
       if(col==n){
           ans.push_back(cases);
           return;
       }
       for(int i=0;i<n;i++){
           if(isSafe(i,col,n,board)){
               board[i][col]=1;
               cases.push_back(i+1);
               solveRec(col+1,n,board,cases);
               cases.pop_back();
               board[i][col]=0;
           }
       }
   }
   
   vector<vector<int>> nQueen(int n) {
       // code here
       vector<vector<int>> board(n,vector<int>(n,0));
       vector<int> cases;
       solveRec(0,n,board,cases);
       return ans;
   }
};




/*
bool isSafe(int row,int col,vector<vector<int> > &board,int n){
    int x=row;
    int y=col;
    
    while(y>=0){
        if(board[x][y]==1){
            return false;
            y--
        }
    }
    
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
            y--;
            x--;
        }
    }
    
     while(x<n && y>=0){
        if(board[x][y]==1){
            return false;
            y--;
            x++;
        }
    }
    return true;
}

void addSolution(vector<vector<int> > &ans,vector<vector<int> > &board,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board,int n){
    if(col==n){
        addSolution(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,ans,board,n);
            board[row][col]=0;
        }
    }
}

vector<vector<int> > nqueens(int n){
    vector<vector<int> > board(n,vector<int>(n,0));
    vector<vector<int> > ans;
    
    solve(0,ans,board,n);
    
    return ans;
}
*/
