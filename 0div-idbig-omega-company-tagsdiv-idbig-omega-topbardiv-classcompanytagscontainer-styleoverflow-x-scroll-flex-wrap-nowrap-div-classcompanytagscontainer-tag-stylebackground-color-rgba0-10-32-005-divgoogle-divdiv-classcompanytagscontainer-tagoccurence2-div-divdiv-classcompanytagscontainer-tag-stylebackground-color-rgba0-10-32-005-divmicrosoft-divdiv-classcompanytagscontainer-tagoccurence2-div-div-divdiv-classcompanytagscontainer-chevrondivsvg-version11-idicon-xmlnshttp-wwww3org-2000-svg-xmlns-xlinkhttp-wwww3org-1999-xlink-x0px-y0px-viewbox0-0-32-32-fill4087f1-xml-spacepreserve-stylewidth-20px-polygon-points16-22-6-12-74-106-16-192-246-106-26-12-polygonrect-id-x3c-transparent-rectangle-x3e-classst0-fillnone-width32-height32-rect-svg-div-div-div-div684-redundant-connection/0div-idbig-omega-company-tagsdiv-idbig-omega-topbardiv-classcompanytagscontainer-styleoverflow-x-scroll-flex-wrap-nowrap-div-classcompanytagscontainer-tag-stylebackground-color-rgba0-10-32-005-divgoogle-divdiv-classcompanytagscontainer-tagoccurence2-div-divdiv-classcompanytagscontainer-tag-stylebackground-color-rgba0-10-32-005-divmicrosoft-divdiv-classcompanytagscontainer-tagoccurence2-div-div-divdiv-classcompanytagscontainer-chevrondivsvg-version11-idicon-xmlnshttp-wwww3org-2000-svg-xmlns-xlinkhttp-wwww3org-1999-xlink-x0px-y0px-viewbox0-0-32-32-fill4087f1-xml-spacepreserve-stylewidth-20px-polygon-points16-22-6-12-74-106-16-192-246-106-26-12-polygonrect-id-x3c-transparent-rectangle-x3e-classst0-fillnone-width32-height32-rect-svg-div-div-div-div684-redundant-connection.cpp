class Solution {
public:
 int findparent(int element, vector<int>&parent)
    {
        if(parent[element]==element)
        return element ;
        return findparent(parent[element],parent);
    }

vector<int> findRedundantConnection(vector<vector<int>>& a) {
   
    vector<int>parent(a.size()+1);
    for(int i =0;i< a.size(); i++)
    {
        parent[i]= i;

    }
    for(vector<int>v: a)
    {
        int ele1= v[0];
        int ele2 = v[1];
        int p1 = findparent(ele1 , parent);
        int p2 = findparent(ele2, parent);
        if(p1==p2)
        return v;
        else
        {
            parent[p2]= p1 ;

        }
    }
    return {};
  
   
}
};
   