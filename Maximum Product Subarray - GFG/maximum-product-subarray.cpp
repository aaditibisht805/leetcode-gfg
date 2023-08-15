//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	   long long maxi=0, prs=1,sus=1;
	   int i=0;
	   if(n==1)
	   return arr[0];
	   while(i<n )
	   {   if(sus==0)
	       sus=1;
	       if(prs==0)
	       prs=1; 
	       prs = prs*arr[i];
	       sus= sus*arr[n-1-i];
	      
	       maxi = max(maxi, max(prs,sus));
	       i++;
	   }
	   return maxi;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends