class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>> ans(V);
        for(int i=0;i<V;i++){
            ans[i].push_back(i);
            for(auto j : adj[i]){
                ans[i].push_back(j);
            }
        }
        return ans;
    }
};
