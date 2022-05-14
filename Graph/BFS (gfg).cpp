class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int visited[V] = {0};
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            ans.push_back(n);
            vector<int> :: iterator i;
            
            for(i = adj[n].begin(); i!=adj[n].end();i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
        return ans;
    }
};
