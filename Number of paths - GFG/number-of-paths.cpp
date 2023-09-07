//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


long long  solve(int n, int m , int i, int j, vector<vector<long long>>&dp)
{
    if(i==n-1 && j==m-1)
    return 1;
    if(i>=n || j >=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    long long right=solve(n, m, i, j+1, dp);
    long long bot =solve(n, m, i+1, j, dp);
    long long sum = right + bot;
    return dp[i][j]=sum;
}
long long  numberOfPaths(int m, int n)
{ int i =0;
  int j =0;
  vector<vector<long long>>dp(n, vector<long long>(m, -1));
  
   long long res = solve(n, m, i, j, dp);
   return res;
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends