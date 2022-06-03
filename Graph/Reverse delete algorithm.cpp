class Graph
{
    int V;
    list<int> *adj;
    vector< pair<int, pair<int, int>> > edges;
    void DFS(int v, bool visited[]);
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    bool isConnected();
    int reverseDeleteMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(v); // Add w to vâ€™s list.
    adj[v].push_back(u); // Add w to vâ€™s list.
    edges.push_back({w, {u, v}});
}
 
void Graph::DFS(int v, bool visited[])
{    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

bool Graph::isConnected()
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    DFS(0, visited);
    for (int i=1; i<V; i++)
        if (visited[i] == false)
            return false;
    return true;
}

int Graph::reverseDeleteMST()
{
    sort(edges.begin(), edges.end());
    int mst_wt = 0;  // Initialize weight of MST 
    //cout << "Edges in MST\n";
    for (int i=edges.size()-1; i>=0; i--)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        adj[u].remove(v);
        adj[v].remove(u);
        if (isConnected() == false)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            //cout << "(" << u << ", " << v << ") \n";
            mst_wt += edges[i].first;
        }
    }
    return mst_wt;
}

class Solution {
  public:
    int RevDelMST(int Arr[], int V, int E) {
        
        Graph g(V);
        
        for(int i=0; i<3*E; i+=3)
            g.addEdge(Arr[i], Arr[i+1], Arr[i+2]);
            
        return g.reverseDeleteMST();
            
    }
};
