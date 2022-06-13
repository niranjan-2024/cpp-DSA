int minFlips (string s)
{
    int count0 = 0,count1 = 0;
    for(int i=0;i<s.length();i++){
        if((i%2==0 && s[i]!='0')||(i%2!=0 && s[i]!='1')){
            count0++;
        }
        if((i%2==0 && s[i]!='1')||(i%2!=0 && s[i]!='0')){
            count1++;
        }
    }
    return min(count0,count1);
}
