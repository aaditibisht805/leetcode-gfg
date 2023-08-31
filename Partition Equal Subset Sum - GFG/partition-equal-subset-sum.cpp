//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


/*void solve(int i, int sum ,  int arr[], vector<int>& m, int n) {
    if (i >= n) {
       
        m.push_back(sum);
        return;
    }
  
    
    
   
    solve( i+1,sum+ arr[i], arr, m, n);
 
    solve( i + 1, sum, arr, m, n);
}

int equalPartition(int N, int arr[]) {
   vector<int> m; //vector<int>dp(N+1, -1);
   // map<int, int> m;

    solve(0, 0, arr, m, N);
    int s=0, c=0;
    for(int i=0; i< m.size();i++)
    s+= m[i];
    int x= s/2;
    if(m.size()%2!=0)
    return 0;
    for(int i=0;i< m.size();i++)
    {
        if(m[i]== x)
      
        return 1;
    }

    return 0;
}
*/

bool solve(int i, int sum, int arr[], int n, vector<vector<int>>& dp) {
    if (sum == 0) {
        return true;
    }
    if (i >= n || sum < 0) {
        return false;
    }
    
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    bool include = solve(i + 1, sum - arr[i], arr, n, dp);
    bool exclude = solve(i + 1, sum, arr, n, dp);

    return dp[i][sum] = include || exclude;
}

bool equalPartition(int N, int arr[]) {
    int totalSum = 0;
    for (int i = 0; i < N; i++) {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0) {
        return false; // Total sum is odd, cannot partition into equal sums
    }

    int targetSum = totalSum / 2;
    vector<vector<int>> dp(N, vector<int>(targetSum + 1, -1));

    return solve(0, targetSum, arr, N, dp);
}





};





//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends