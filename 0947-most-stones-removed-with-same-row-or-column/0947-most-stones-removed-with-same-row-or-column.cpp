class Solution {
public:
int findpar(int u , vector<int>&par)
{
    if(u==par[u])
    return u;
    else
    {
        return par[u]= findpar(par[u], par);
    }
}
  void unionbyrank(int u , int v, vector<int>&par, vector<int>&rank)
  {
      int x= findpar(u, par);
      int y = findpar(v,par);
      if(x==y)
      {
          return ;
      }
      else if(rank[x]>rank[y])
      {
          par[y]=x;
      }
      else if(rank[x]<rank[y])
      {
          par[x]=y;
      }
      else
      {
          par[y]=x;
          rank[x]++;
      }
  }
    int removeStones(vector<vector<int>>& stones) {
       
        int rowsize=0;  
        int colsize=0;
        // this is done because we are only having the coordinates 
        //in form of vector. to find the size in 2d plane of rows and columns below loop required 
        for(auto x: stones)
        {
            rowsize= max(rowsize, x[0]);
            colsize= max(colsize, x[1]);
        }
        int n = rowsize+colsize+1; // converting 2d to 1d plane 

       
        
        
        vector<int>rank(n+1, 0);
        vector<int>par(n+1, 0);
        for(int i =0;i<=n ; i++)
        {
            par[i]=i;
        }

        unordered_map<int, int> mp;
        // map  stores the unique nodes that are present 
        for(auto it : stones)
        {
            int rownode= it[0];
            int colnode = it[1]+1+rowsize;
            unionbyrank(rownode,colnode, par, rank);
            mp[rownode]=1;
            mp[colnode]=1;


        }
        int components=0;
        for(auto it: mp)
        {
            if(findpar(it.first, par)==it.first)
            components++;
        }
        int m = stones.size();
        // total stones - no of components gives the result 
        return m-components;
        
    }
};