class Solution {
public:
    int findparent(int u, vector<int> &par)
    {  if(par[u]==u)
        return u ;
        else
        return par[u]= findparent(par[u], par);

    }
    void unionbyrank(int u , int v , vector<int> &par, vector<int> &rank )
    {
        int x= findparent(u, par);
        int y = findparent(v, par);
        if(x==y)
        return ;
        else if(rank[x]< rank[y])
        {
            par[x]= y;

        }
        else if(rank[x]>rank[y])
        {
            par[y]= x;
            
        }
        else
        {
            par[y]= x;
            rank[x]++;

        }
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        // extra edeges  required  no. of components -  1
        // we just have to find extra edges 
       vector<int>par(n+1, 0);
       vector<int>rank(n+1, 0);
       for(int i =0;i<= n ; i++)
       { par[i]=i;
      
       }
       int extraedeges =0;
        for(auto it : arr)
        {
       
                int u = it[0];
                int v = it[1];
                if(findparent(u, par)==findparent(v, par)) // ultimate parent same means extra edges present that makes cycles 
                extraedeges ++;
                else
                {
                    // differnt ultimate parent 
                    unionbyrank(u, v, par, rank);
                }
               
         }  // total components counting 
        int cn =0;
          for(int i =0;i< n ; i++)
                {
                    if(par[i]==i)
                    cn++;
                }
                if(extraedeges>= (cn-1))
                return cn-1 ;
                return -1;
                }


      
        
    
};