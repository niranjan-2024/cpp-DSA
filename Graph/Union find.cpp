class Solution
{
    public:
    
    int find(int x, int parent[])
    {
        if(parent[x] == x)
        {
            return x;
        }
        
        parent[x] = find(parent[x], parent);
        
        return parent[x];
    }
    
    //Function to merge two nodes a and b.
    void union_(int x, int y, int parent[], int rank1[]) 
    {
        
        int x_rep = find(x, parent);
        
        int y_rep = find(y, parent);
        
        if(x_rep == y_rep)
        {
            return;
        }
        
        if(rank1[x_rep] < rank1[y_rep])
        {
            parent[x_rep] = y_rep;
        }
        else if(rank1[x_rep] > rank1[y_rep])
        {
            parent[y_rep] = x_rep;
        }
        else
        {
            parent[y_rep] = x_rep;
            
            rank1[x_rep]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int parent[], int rank1[])
    {
        return find(x, parent) == find(y, parent);
    }
};
