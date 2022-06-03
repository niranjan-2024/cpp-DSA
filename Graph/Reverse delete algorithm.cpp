struct Node{
    int u;
    int v;
    int wt;
    Node(int u, int v, int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};

class ReverseAlgorithm{

    private:
        int V;
        list<int>* adj;
        vector<Node> edges;
        
    public:
    
        ReverseAlgorithm(int V){
            this->V=V;
            adj=new list<int>[V];
        }
        
        static bool cmp(Node &n1, Node &n2){
            return n1.wt>n2.wt;
        }
        
        void addEdge(int u, int v, int wt){
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({u,v,wt});
        }
        
        void DFS(int v, vector<bool> &vis){
            vis[v]=true;
            for(auto nei: adj[v]){
                if(vis[nei]==false){
                    DFS(nei,vis);
                }
            }
        }
        
        bool isConnected(){
            vector<bool> vis(V,false);
            DFS(0,vis);
            for(int i=0;i<V;i++){
                if(vis[i]==false){
                    return false;
                }
            }
            return true;
        }
        
        int isMSTAlgorithm(){
            int MST=0;
            sort(edges.begin(),edges.end(),cmp);
            for(auto n: edges){
                int u=n.u;
                int v=n.v;
                adj[u].remove(v);
                adj[v].remove(u);
                if(isConnected()==false){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    MST+=n.wt;
                }
            }
            return MST;
        }
};

class Solution {
  public:
    int RevDelMST(int Arr[], int V, int E) {
         ReverseAlgorithm RA(V);
        for(int i=0;i<3*E;i+=3){
            RA.addEdge(Arr[i],Arr[i+1],Arr[i+2]);
        }
        return RA.isMSTAlgorithm();
    }
};
