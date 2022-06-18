class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        vector<int> v;
        unordered_set< int >st(a,a+n);
        for(int i=0;i<m;i++){
            if(st.find(b[i])!=st.end()){
                v.push_back(b[i]);
                st.erase(b[i]);
            }
        }
        return v.size();
    }
};
