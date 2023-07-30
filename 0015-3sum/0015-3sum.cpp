class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {  vector<vector<int>>vf; 
       sort(nums.begin(),nums.end());
      set<vector<int>>s;
      int j,k;
    
    int sum=0;
    for(int i=0;i<nums.size()-2;i++)
    {   vector<int>v;
        j=i+1; k=nums.size()-1;
      sum=0;
       while(j<k)
        {
            sum= nums[i]+nums[j]+nums[k];
            if(sum==0)
            {
              
                s.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
                
            
            }
            else if(sum<0)
            {
                j++;

            }
           else 
            {
                k--;
            }
           
        }
    }
   
    
     for(auto x: s)
         vf.push_back(x);
     return vf;
     

        
    }
};