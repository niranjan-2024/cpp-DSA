string printSequence(string S)
{
   unordered_map<char,pair<int,int>>mp;
   mp['A']=make_pair(2,1);
   mp['B']=make_pair(2,2);
   mp['C']=make_pair(2,3);
   mp['D']=make_pair(3,1);
   mp['E']=make_pair(3,2);
   mp['F']=make_pair(3,3);
   mp['G']=make_pair(4,1);
   mp['H']=make_pair(4,2);
   mp['I']=make_pair(4,3);
   mp['J']=make_pair(5,1);
   mp['K']=make_pair(5,2);
   mp['L']=make_pair(5,3);
   mp['M']=make_pair(6,1);
   mp['N']=make_pair(6,2);
   mp['O']=make_pair(6,3);
   mp['P']=make_pair(7,1);
   mp['Q']=make_pair(7,2);
   mp['R']=make_pair(7,3);
   mp['S']=make_pair(7,4);
   mp['T']=make_pair(8,1);
   mp['U']=make_pair(8,2);
   mp['V']=make_pair(8,3);
   mp['W']=make_pair(9,1);
   mp['X']=make_pair(9,2);
   mp['Y']=make_pair(9,3);
   mp['Z']=make_pair(9,4);
   mp[' ']=make_pair(0,1);
   string ans="";
   for(int i=0;i<S.size();i++)
   {
       for(int j=0;j<mp[S[i]].second;j++)
       {
           ans+=to_string(mp[S[i]].first);
       }
   }
   return ans;
}
