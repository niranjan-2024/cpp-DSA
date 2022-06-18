class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            unordered_map<int,int> a,b,c;
            for(int i=0;i<n1;i++){
                a[A[i]]++;
            }
            for(int i=0;i<n2;i++){
                b[B[i]]++;
            }
            for(int i=0;i<n3;i++){
                c[C[i]]++;
            }
            for(int i=0;i<n1;i++){
                if(a[A[i]]>0 && b[A[i]]>0 && c[A[i]]>0){
                    ans.push_back(A[i]);
                }
                a[A[i]] = 0;
            }
            return ans;
        }

};
