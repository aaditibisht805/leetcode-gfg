//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
    /*   if(arr[0]==0){
            return -1;
        }
        int curr=0,j=0,f=0,i=0;
        for(i=0;i<n-1;i++){
            f=max(f,arr[i]+i);
            if(i==curr){
                if(curr==f) return -1;
                curr=f;
                j++;
            }
        }*/
         int curr=0,jump=0,maxi=0 ;
        if(arr[0]==0)
        return -1;
        else
        {
           //  int curr=0,jump=0,maxi=0 ;
             for(int i=0;i<n-1;i++)
             {
                 maxi = max(maxi,arr[i]+i);
                 if(i==curr)
                 {
                     if(curr==maxi)
                     return -1;
                     else
                     {
                         curr=maxi;
                         jump++;
                         
                     }
                 }
             }
            
        }
         return jump;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends