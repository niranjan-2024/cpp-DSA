class Solution {
  public:
    
    void dfs(vector<int> &ans,vector<bool> &visited,vector<int> adj[],int node){
        if(visited[node]) return;
        ans.push_back(node);
        visited[node] = true;
        for(auto i:adj[node]){
            dfs(ans,visited,adj,i);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> ans;
        dfs(ans,visited,adj,0);
        return ans;
    }
};
