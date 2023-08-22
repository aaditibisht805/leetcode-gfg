//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {int sum=0,max=0;
        vector<int>v;
        for(int i=0;i< matrix.size();i++)
        {  sum=0;
            for(int j=0;j<matrix[i].size();j++)
            {  sum+= matrix[i][j];
            
                
            }
            
           v.push_back(sum);
           
            if(sum>=max )
            {
                max= sum;
            }
            sum=0;
             for(int j=0;j<matrix[i].size();j++)
            {  sum+= matrix[j][i];
            
                
            }
              if(sum>=max )
            {
                max= sum;
            }
           
        }     
            
        
        int ans=0,x;
        for(int i=0;i<v.size();i++)
        {  if(max != v[i])
          {  x= abs(max- v[i]);
            ans+= x;
              
          }
        }
        
        return ans ;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends