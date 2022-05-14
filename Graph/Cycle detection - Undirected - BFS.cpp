class Solution {
    
  public:
  bool iscyclicBFS(int src,unordered_map<int,bool> &visited,vector<int> *adj,int V){
      unordered_map<int,int> parent;
      parent[src] = -1;
      visited[src] = 1;
      queue<int> q;
      q.push(src);
      while(!q.empty()){
          int front = q.front();
          q.pop();
          for(auto n:adj[front]){
              if(visited[n]==true && n!=parent[front]){
                  return true;
              }
              else if(!visited[n]){
                  q.push(n);
                  visited[n] = 1;
                  parent[n] = front;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       unordered_map<int,bool> visited;
       for(int i=0;i<V;i++){
           if(!visited[i]){
               bool ans = iscyclicBFS(i,visited,adj,V);
               if(ans == true){
                   return true;
               }
           }
       }
       return false;
    }
};
