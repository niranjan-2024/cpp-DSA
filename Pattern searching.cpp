bool searchPattern(string str, string pat)
{
    int n=pat.size();
    for(int i=0;i<str.size()-n+1;i++){
        if(str[i]==pat[0]){
            string temp = str.substr(i,n);
            if(temp==pat){
                return true;
            }
        }
    }
    return false;
}
