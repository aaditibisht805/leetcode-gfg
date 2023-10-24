//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[] , int n , int i, vector<vector<int>>&dp)
  {
      if(i==0)
      return n*price[0];
      int rodlength = i+1;
      if(dp[i][n]!=-1)
      return dp[i][n];
      int take =0;
      if(rodlength<=n)
      { take = price[i]+solve(price,n-rodlength,i, dp);
      }
      int nottake = 0+solve(price, n, i-1, dp);
      
      return dp[i][n]= max(take, nottake );
  }
    int cutRod(int price[], int n) {
         vector<vector<int>>dp(n,vector<int>(n+1,  -1));
       return solve(price, n, n-1, dp);
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends