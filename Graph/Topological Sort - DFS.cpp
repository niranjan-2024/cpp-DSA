class Solution
{
	public:
	void topsort(int node, unordered_map<int,bool> &visited,stack<int> &s,vector<int> adj[]){
	    visited[node] = 1;
	    for(auto neighbour:adj[node]){
	        if(!visited[neighbour]){
	            topsort(neighbour,visited,s,adj);
	        }
	    }
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int,bool> visited;
	    stack<int> s;
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           topsort(i,visited,s,adj);
	       }
	   }
	   vector<int> ans;
	   while(!s.empty()){
	       ans.push_back(s.top());
	       s.pop();
	   }
	   return ans;
	}
};
