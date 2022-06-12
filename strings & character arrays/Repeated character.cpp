class Solution
{
  public:
    char firstRep (string s)
    {
        int arr[26] = {0};
        int index = 0;
        for(int i=0;i<s.length();i++){
            index = s[i] - 'a';
            arr[index]++;
        }
        
        char a = '0';
        int ind;
        for(int i=0;i<s.length();i++){
            int ind = s[i] - 'a';
            if(arr[ind]>1){
                a = ind + 'a';
                break;
            }
        }
        if(a=='0'){
            return '#';
        }
        return a;
    }
};
