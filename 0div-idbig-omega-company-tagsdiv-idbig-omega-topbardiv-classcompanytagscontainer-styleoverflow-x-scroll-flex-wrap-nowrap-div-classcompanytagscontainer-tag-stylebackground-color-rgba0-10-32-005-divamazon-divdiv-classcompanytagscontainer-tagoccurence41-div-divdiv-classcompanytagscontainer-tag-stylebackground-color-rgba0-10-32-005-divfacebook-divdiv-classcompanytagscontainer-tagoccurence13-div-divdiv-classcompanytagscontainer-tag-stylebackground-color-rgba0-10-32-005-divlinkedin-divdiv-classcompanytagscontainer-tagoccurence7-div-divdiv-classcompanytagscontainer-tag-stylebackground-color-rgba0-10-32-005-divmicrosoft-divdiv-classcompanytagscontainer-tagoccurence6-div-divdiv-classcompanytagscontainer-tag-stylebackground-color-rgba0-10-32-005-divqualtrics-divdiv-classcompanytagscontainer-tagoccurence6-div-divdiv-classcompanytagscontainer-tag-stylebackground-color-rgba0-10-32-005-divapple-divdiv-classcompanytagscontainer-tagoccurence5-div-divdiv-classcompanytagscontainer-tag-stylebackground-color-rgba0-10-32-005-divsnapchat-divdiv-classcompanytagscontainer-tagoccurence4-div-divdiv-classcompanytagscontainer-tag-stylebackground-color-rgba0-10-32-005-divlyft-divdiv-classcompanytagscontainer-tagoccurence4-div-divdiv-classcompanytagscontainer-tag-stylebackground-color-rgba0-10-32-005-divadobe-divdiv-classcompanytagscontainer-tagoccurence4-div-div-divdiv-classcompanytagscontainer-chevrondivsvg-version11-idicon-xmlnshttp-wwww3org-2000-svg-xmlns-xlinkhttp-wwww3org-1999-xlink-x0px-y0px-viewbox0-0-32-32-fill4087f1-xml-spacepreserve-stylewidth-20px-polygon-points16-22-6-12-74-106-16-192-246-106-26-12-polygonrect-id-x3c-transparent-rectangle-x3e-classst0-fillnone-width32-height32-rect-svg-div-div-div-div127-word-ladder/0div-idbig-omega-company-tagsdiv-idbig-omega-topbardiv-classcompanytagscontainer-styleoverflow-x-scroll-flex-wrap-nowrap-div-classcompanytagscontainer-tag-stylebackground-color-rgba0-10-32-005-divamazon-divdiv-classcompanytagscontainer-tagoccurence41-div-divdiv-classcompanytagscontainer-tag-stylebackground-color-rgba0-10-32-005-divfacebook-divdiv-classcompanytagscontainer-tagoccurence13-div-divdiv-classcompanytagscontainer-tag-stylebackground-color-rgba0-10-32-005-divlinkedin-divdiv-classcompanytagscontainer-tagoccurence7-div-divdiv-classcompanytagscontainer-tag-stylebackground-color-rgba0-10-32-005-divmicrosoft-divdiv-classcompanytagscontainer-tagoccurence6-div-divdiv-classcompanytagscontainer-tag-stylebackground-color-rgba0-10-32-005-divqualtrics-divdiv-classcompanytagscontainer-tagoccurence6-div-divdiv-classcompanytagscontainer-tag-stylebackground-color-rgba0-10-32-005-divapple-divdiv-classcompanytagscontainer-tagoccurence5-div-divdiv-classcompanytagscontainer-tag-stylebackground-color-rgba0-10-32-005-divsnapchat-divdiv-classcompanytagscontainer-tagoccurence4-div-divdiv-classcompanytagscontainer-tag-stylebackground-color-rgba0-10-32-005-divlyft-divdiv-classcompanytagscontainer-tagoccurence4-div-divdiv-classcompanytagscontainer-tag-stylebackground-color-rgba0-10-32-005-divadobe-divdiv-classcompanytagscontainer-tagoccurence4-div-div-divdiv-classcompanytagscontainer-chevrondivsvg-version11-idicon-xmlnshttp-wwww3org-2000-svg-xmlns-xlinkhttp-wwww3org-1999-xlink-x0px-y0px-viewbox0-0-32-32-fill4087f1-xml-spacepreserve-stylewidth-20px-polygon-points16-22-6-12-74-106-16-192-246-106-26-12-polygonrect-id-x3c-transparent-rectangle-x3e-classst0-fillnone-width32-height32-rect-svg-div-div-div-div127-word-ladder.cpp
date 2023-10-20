class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>&a )
    {
        set<string> s(a.begin(), a.end());
        queue<pair<string, int>> q;
        q.push({bw,1});
        s.erase(bw);
   
        while(!q.empty())
        {
            string ans=  q.front().first;
          
            int steps = q.front().second;
           
            q.pop();
          
            for(int i=0;i<ans.size();i++)
            {  char m = ans[i];
              for(char ch = 'a'; ch<='z'; ch++)
              {
                  ans[i]=ch;
                
                  if(s.find(ans)!=s.end())
                  {
                      q.push({ans, steps+1});
                      s.erase(ans);
                     
                  }
                  
              }
              ans[i]=m;
              if(ans==ew)
              return steps;
           
            }
           }
      
        return 0;
        

    }
};