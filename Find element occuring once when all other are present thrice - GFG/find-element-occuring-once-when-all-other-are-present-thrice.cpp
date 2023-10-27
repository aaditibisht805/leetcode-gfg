//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        int ans =00000000, c1=0,c0=0;
        for(int i =0;i<32; i++)
        {  c1=0; c0=0;
            
            for(int j =0;j<n ; j++)
            {
                if((1<<i)& arr[j])
                c1++;
                else
                c0++;
                
            }
            if(c0%3==0)
            ans= ans|(1<<i);
        }
        return ans ;
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends