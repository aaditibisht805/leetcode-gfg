class Solution {
public:
   void  solve(int index , int k ,  vector<vector<int>> &v ,vector<int>&temp,int n)
    {
         if(temp.size()==k)
         {  v.push_back(temp);
            return;
         }
         if(index > n)
         return ;
         else
         { 
             temp.push_back(index);
             solve(index+1, k, v, temp,n);
              temp.pop_back();
              solve(index+1, k, v, temp,n);
          }

           
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> v;
       vector<int>temp;
      solve(1 , k, v, temp,n);
      return v;

        
    }
};