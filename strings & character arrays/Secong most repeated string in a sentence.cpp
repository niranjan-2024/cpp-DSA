class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mp;
        
        //store the frequency of each string in map
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        //store frequencies in a vector and sort to get second largest freq
        vector<int> v;
        for(auto i : mp){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        int a = v[v.size()-2];
        
        //give ans
        string ans="";
        for(auto i:mp){
            if(a == i.second){
                ans = i.first;
            }
        }
        return ans;
    }
};
