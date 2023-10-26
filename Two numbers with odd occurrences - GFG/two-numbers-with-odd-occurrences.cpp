//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int a[], long long int n)  
    { vector<long long int > v;
        long long int x =0, b=0, c=0, xrsb;
        for(int i =0;i< n ;i++)
        {
            x=x^a[i];
        }
        xrsb = x &(-x);
        for(int i =0;i< n;i++)
        {
            if((a[i]&xrsb)==0)
            {
                b = b^a[i];
            }
           
        }
        c = x^b;
         v.push_back(max(b, c));
         v.push_back(min(b,c));
         return v ;
        
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends