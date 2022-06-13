class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        map<string, vector<string>> map;
        
        for(auto i : string_list){
           string x = i;
           sort(x.begin(), x.end());
           map[x].push_back(i);
       }
       
       for(auto j : map){
           ans.push_back(j.second);
       }
       return ans;
    }
};
