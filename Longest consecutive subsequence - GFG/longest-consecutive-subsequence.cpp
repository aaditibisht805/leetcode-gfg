//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
       set<int>s;vector<int>a;
        if(n==1)
       return 1;
       for(int i=0;i< n;i++)
       {
           s.insert(arr[i]);
       }
       for(auto x: s )
       {
           a.push_back(x);
       }
       int j=1, i=0,c=1;
       vector<int>v;
      
       while(i<a.size()-1)
       {
           if(a[i+1]==a[i]+1)
         {
             c++;
             
         }
           else
           {v.push_back(c);
             
           c=1;}
           i++;
                    
       }
       v.push_back(c);
       int maxi = *max_element(v.begin(), v.end());
       return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends