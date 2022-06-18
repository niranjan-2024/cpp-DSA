class Solution{
    public:
    int n,m;
    vector<vector<string>> s;
    vector<string> v;
    
    void dfs(vector<vector<string>> &list,int i,int j){
        if(i==n||j==m){
            s.push_back(v);
            return;
        }
        for(int k=0;k<m;k++){
            v.push_back(list[i][k]);
            dfs(list,i+1,k);
            v.pop_back();
        }
    }
    
    vector<vector<string>> sentences(vector<vector<string>>&list){
        n = list.size();
        m = list[0].size();
        dfs(list,0,0);
        return s;
    }
};
