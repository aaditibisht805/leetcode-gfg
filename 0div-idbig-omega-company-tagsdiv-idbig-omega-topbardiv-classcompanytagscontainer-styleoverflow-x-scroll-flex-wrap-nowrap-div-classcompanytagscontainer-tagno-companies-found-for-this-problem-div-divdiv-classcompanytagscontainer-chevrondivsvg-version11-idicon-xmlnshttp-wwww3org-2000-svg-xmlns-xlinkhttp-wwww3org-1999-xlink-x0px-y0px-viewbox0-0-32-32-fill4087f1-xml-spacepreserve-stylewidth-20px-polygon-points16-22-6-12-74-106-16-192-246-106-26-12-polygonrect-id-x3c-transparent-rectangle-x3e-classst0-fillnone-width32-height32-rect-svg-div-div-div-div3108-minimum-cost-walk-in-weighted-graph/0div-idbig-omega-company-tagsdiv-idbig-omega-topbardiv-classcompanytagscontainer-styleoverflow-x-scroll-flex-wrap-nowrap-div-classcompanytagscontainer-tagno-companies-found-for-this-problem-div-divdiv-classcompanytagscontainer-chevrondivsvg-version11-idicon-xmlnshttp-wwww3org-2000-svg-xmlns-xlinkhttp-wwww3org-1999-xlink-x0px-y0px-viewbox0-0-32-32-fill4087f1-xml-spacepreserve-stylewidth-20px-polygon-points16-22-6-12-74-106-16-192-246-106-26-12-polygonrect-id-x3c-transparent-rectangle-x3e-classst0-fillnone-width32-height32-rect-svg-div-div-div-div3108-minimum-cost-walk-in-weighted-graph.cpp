
class Solution {
public:
    int findparent(int u , vector<int>&par)
    {
        if(par[u]==u)
        return u;
        else
        return par[u]=findparent(par[u], par);

    }
    void unionbyrank(int u, int v, vector<int>&par, vector<int>&rank)
    {
         int x= findparent(u, par);
         int y = findparent(v, par);
         if(x==y)
         return ;
         else if(rank[x]>rank[y])
         {
            par[y]=x;
            return;
 
         }
         else if(rank[x]<rank[y])
         {
             par[x]=y;
             return;

         }
         else
         {
             par[y]=x;
             rank[x]++;
         }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // graph construct ;
        vector<int> par(n+1);
        vector<int> rank(n+1, 0);
        vector<int>res;
        map<int, int>mp;
        for(int i =0;i<=n ; i++)
        {
            par[i]=i;

        } 

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if(findparent(u, par)!=findparent(v, par))
            {
                unionbyrank(u, v, par, rank);  // join components 
            }
        }
        for(auto it:edges)
        {
            int ultpar= findparent(it[0],par);
            if(mp.find(ultpar)==mp.end())
            mp[ultpar]= it[2];
            else
            mp[ultpar]&=it[2];
        }
        for(auto it : query)
        {
            int source= it[0];
            int dest= it[1];
            if(findparent(source, par)!=findparent(dest, par))
            res.push_back(-1);
            else
            res.push_back(mp[findparent(source, par)]);  
        }
        return res;
        
    }
};
