class Solution {
public:
 
   /* void solve(int i, int k, string s, string &t) {
    if (t.size() >= k) {
        return;
    }

    if (s[i] >= 'a' && s[i] <= 'z') {
        t += s[i];
        solve(i + 1, k, s, t);
    } 
    else if (s[i] >= '0' && s[i] <= '9') {
        int num = s[i] - '0';
        string ans = t; 
        for (int j = 1; j < num; ++j) {
            t += ans; 
        }
        solve(i + 1, k, s, t);
    }
}
*/
string decodeAtIndex(string s, int k) {
 
   unsigned  long long size=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&& s[i]<='z')
        size++;
        else
        size*=(s[i]-'0');
    }
     if(size==0)
     return"";
    for(int i = s.size()-1;i>=0;i--)
    {     k=k % size;
        if(  k%size==0 && s[i]>='a'&& s[i]<='z')
        return string(1, s[i]);
        else if(s[i]>='1'&& s[i]<='9')
        {
             
               size =(size/ (s[i]-'0'));
              
        }
        else
        size--;
        if(size==0)
        return string(1,s[k-1]);
    }
   
    return string(1,s[k-1]);
}



};