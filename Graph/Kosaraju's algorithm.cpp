class Solution
{
	public:
	
	void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,vector<int> adj[]){
	    vis[node] = 1;
	    for(auto nbr : adj[node]){
	        if(!vis[nbr]){
	            dfs(nbr,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	void revDFS(int node,unordered_map<int,bool> &vis,vector<int> transpose[]){
	    vis[node] = 1;
	    for(auto nbr:transpose[node]){
	        if(!vis[nbr]){
	            revDFS(nbr,vis,transpose);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        
        stack<int> st;
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto nbr:adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!vis[top]){
                count++;
                revDFS(top,vis,transpose);
            }
        }
        return count;
    }
};
