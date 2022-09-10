class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          int maxi = INT_MIN, mini = INT_MAX;
          priority_queue<node*,vector<node*>,compare> minHeap;
          
          for(int i=0;i<k;i++){
              int element = a[i][0];
              mini = min(mini,element);
              maxi = max(maxi,element);
              minHeap.push(new node(element,i,0));
          }
          
          int start = mini, end = maxi;
          
          while(!minHeap.empty()){
              node* temp = minHeap.top();
              minHeap.pop();
              
              mini = temp->data;
              
              if(maxi-mini < end-start){
                  end = maxi;
                  start = mini;
              }
              
              if(temp->col + 1 < n){
                  maxi = max(maxi,a[temp->row][temp->col + 1]);
                  minHeap.push(new node(a[temp->row][temp->col + 1],temp->row,temp->col + 1));
              }
              else{
                  break;
              }
          }
          return {start,end};
    }
};
