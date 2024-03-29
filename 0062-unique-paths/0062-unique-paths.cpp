class Solution {
public:
  int   solve(int i, int j, int n , int m, vector<vector<int>>&dp )
    {
        if(i==n-1 && j==m-1)
        {
            return 1;

        }
        if(i>= n|| j>=m )
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];

       int  right = solve(i, j+1,n, m, dp );
       int bottom = solve(i+1, j, n, m, dp);
       return dp[i][j]=  right + bottom ;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m , -1));
        int r= solve(0, 0, n, m, dp);
        return r;
        
    }
};