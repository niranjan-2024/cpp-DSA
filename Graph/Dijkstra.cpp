class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
     const int INF=1e9;

   vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
   {
       
    vector<int>dist(V,INF);
    dist[S]=0;
     
       set<vector<int>>st;
       st.insert({0,S});
       
       while(!st.empty()){
           auto x=*(st.begin());
           st.erase(x);
           for(auto it : adj[x[1]]){
               if(dist[it[0]]>dist[x[1]]+it[1]){
                   st.erase({dist[it[0]],it[0]});
                   dist[it[0]]=dist[x[1]]+it[1];
                   st.insert({dist[it[0]],it[0]});
               }
           }
           
       }
       return dist;
   }
};
