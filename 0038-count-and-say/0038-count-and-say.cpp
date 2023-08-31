class Solution {
public:
    string countAndSay(int n) {
        string a = "1";
        for(int i=2;i<= n;i++)
        {
           vector<pair<char,int>>v; int c=1;
            for(int j =0;j< a.size()-1;j++)
            { 
                if(a[j]==a[j+1])
                c++;
                else
                {
                    v.push_back(make_pair(a[j], c));
                    c=1;
                }
            }
             v.push_back(make_pair(a.back(), c));
            a="";
            for(auto x: v)
            {
                a=a+to_string(x.second)+ x.first;
                
            }
            v.clear();
        }
        return a;
        
    }
  

};