//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
    /* sort(arr, arr+n);
     int i=0, j= n-1;
     int sum =0;
     int c=0;
     while(i<j)
     {
         sum=arr[i]+arr[j];
         if(sum==k)
        { c++; i++; 
        }
         else if(sum>k)
         {
             j--;
         }
         else
         {
             i++;
         }
         
     }
     return c;*/
    
      map<int,int> m;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(m.find(k-arr[i]) != m.end()){
                count += m[k-arr[i]];
            }
        
                m[arr[i]]++;
        } 
    return count;
     
     
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends