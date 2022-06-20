string isSubset(int a1[], int a2[], int n, int m) {
    vector<int> v(100000,0);
    for(int i=0;i<n;i++){
        v[a1[i]] = 1;
    }
    for(int i=0;i<m;i++){
        if(v[a2[i]]!=1){
            return "No";
        }
    }
    return "Yes";
}
