class Solution {
  public:

void dfs(int node,vector<int> &disc,vector<int> &low,int &timer,int parent,
  unordered_map<int,bool> &visited,vector<int> adj[],vector<int> &Ap)
  {
      visited[node]=true;
      disc[node]=low[node]=timer++;
      
      int child=0;
      
      for(auto nbr : adj[node])
      {
          if(nbr==parent)
          {
              continue;
          }
          
          if(!visited[nbr])
          {
              dfs(nbr,disc,low,timer,node,visited,adj,Ap);
              
              low[node]=min(low[node],low[nbr]);
              
              if(low[nbr]>=disc[node] && parent!=-1)
              {
                  Ap[node]=1;
              }
              child++;
          }
          else
          {
              low[node]=min(low[node],disc[nbr]);
          }
      }
      
      if(parent==-1 && child>1)
      {
          Ap[node]=1;
      }
  }
  vector<int> articulationPoints(int V, vector<int>adj[]) {
     
     int timer = 0;
     vector<int> disc(V);
     vector<int> low(V);
     int parent =-1;
     
     //ans intialiy false mark
     vector<int> Ap(V,0);
     unordered_map<int,bool> visited;
     
     for(int i=0;i<V;i++)
     {
         disc[i]=-1;
         low[i]=-1;
     }
     
     for(int i=0;i<V;i++)
     {
         if(!visited[i])
         {
             dfs(i,disc,low,timer,parent,visited,adj,Ap);
         }
     }
     
     vector<int> ans;
     for(int i=0;i<Ap.size();i++)
     {
         if(Ap[i]!=0)
         {
             ans.push_back(i);
         }
     }
     if(ans.size()==0){
         ans.push_back(-1);
     }
     
     return ans;
  }
};
