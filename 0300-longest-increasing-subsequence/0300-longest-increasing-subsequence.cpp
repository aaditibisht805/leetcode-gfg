class Solution {
public:
int solve(vector<int>&nums , int i, int prev, vector<vector<int>>&dp)
{
    if(i>=nums.size())
    return 0;
    if(dp[i][prev+1]!=-1)
    return dp[i][prev+1];
    else
    { int pick=0;
      int   notpick  = 0+solve(nums, i+1, prev, dp);
        if(prev==-1)
        {
         pick=1+solve(nums, i+1, i, dp);
        }
        else if(nums[i]>nums[prev])
        {
              pick= 1 + solve(nums, i+1, i, dp);
        }

        
      return dp[i][prev+1]= max(pick,notpick);
    
        
    }
}
    int lengthOfLIS(vector<int>& nums) {
    //vector<int>dp(nums.size(), -1);
      vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int r = solve(nums, 0,-1, dp);
        return r;
    }
};