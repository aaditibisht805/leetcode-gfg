class Solution {
public:

    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n, 0);
      
         //tabulation 
    dp[0]=nums[0]; 
    int neg=0;
    for(int i=1;i< n;i++)
    { int table = nums[i]+0;
        if(i>1)
        table+= dp[i-2];
      int  nontable = 0+ dp[i-1];
        dp[i]= max (table, nontable );

    }
    return dp[n-1];
        
    }
};