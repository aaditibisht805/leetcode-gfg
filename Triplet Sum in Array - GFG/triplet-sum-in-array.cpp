//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    { 
        int i, j, k, sum=0;
        sort(arr, arr+n);
        for(int i=0;i< n ;i++)
        {   sum = arr[i]; j =i+1; k = n-1;
            while(j<k)
            { sum=arr[i]+arr[k]+arr[j];
               if(sum==x)
               return true;
                if(sum>x)
                k--;
                else
                j++;
                
            }
        }
       return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends