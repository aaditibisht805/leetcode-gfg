//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool solve(int i, int sum, int arr[], int n, vector<vector<int>>& dp) {
    if (sum == 0) {
        return true;
       
}
    if(i>=n|| sum < 0) {
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