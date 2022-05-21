class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        unordered_map<int,list<pair<int,int> > > adja;
        for(int i=0;i<V;i++){
            int u = adj[i][0];
            int v = adj[i][1];
            int w = adj[i][2];
            
            adja[u].push_back(make_pair(u,w));
            adja[v].push_back(make_pair(v,w));
        }
        
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
        }
        
        set<pair<int,int> > st;
        
        dist[S] = 0;
        st.insert(make_pair(0,S));
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int nodeDistance = top.first;
            int topNode = top.second;
            
            st.erase(top);
            
            for(auto neighbour:adj[top[1]]){
                if(nodeDistance + neighbour.second < dist[neighbour[0]]){
                    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }
        return dist;
    }
};
