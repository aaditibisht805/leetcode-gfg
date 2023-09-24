//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
      int solve(string s, string r, int i ,int j, vector<vector<int>>&dp)
    {   
        if(i>=s.size()||j >=r.size())
        return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
  
       
        if(s[i]==r[j])
        {
         return  dp[i][j]=   1+ solve(s, r, i+1, j+1, dp);
        }
       return dp[i][j]=   max(solve(s,r, i+1, j, dp), solve(s, r, i, j+1, dp));
     
         

    }
    int longestPalinSubseq(string s) {
        string r = s;
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        reverse(r.begin(), r.end());
        return solve(s, r,0, 0, dp);
    }
   
    
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends