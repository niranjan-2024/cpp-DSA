class Solution {
public:
		int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<pair<int,pair<int,int>>> adj;
	    
	    for(int i=0;i<edges.size();i++){
	        int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj.push_back({u,{v,w}});
	    }
	    
	    vector<int> dist(n,1e6+7);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	        for(auto edge:adj){
	            int u=edge.first;
	            int v=edge.second.first;
	            int w=edge.second.second;
	            if(dist[v]>dist[u]+w){
	                
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    
        for(auto edge:adj){
            int u=edge.first;
            int v=edge.second.first;
            int w=edge.second.second;
            
            if(dist[v]>dist[u]+w){
                return 1;
            }
        }
        
	    return 0;
	}
};
