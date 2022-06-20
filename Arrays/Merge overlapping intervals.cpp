class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        
        v.push_back(intervals[0]);
        int end = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[end][0] && intervals[i][0]<v[end][1]){
                if(intervals[i][1]>v[end][1]){
                    v[end][1] = intervals[i][1];
                }
            }
            else if(intervals[i][0] == v[end][1]){
                v[end][1] = intervals[i][1];
            }
            else{
                v.push_back(intervals[i]);
                end++;
            }
        }
        return v;
    }
};
