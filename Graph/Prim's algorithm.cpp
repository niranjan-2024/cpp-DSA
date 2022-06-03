class Solution
{
	public:
	//Prims Algorithm : TC - > O(V^2) can be reduced to O(ELogV) using min priority queue
int spanningTree(int V, vector<vector<int>> adj[])
   {
       //mst, key, parent
       //key stores weight corresponding a node
       //mst keeps track which node is present in mst
       //parent will keep track of the node corressponding to the index
       
       vector<int> key(V, INT_MAX);
       vector<bool> mst(V, false);
       vector<int> parent(V, -1);
       
       key[0] = 0;
       parent[0] = -1;
       
       for(int i = 0 ; i < V ; i++){
           int mini = INT_MAX;
           int u;
           //Step 1 : Find node with min weight using key vector
           //We can also use priority queue to reduce the time complexity
           for(int v = 0 ; v < V ; v++){
               if(mst[v] == false && key[v] < mini){
                   //node with idx v has min weight
                   u = v;
                   mini = key[v];
               }
           }
           //Step 2 : Mark min weight node true
           mst[u] = true;
           
           //Step 3 : Traverse adjacent of u 
           for(auto neighbour : adj[u]){
               int v = neighbour[0]; //Neighbour node of u
               int w = neighbour[1]; //Weight from u to v
               //3.1 : If v is not in MST and its weight is < previous weight then update it
               if(mst[v] == false && w < key[v]){
                   key[v] = w;
                   //Initialize parent of v to u
                   parent[v] = u;
               }
           }
       }
       int sum = 0;
       for(auto it : key){
           sum += it;
       }
       return sum;
   }
};
