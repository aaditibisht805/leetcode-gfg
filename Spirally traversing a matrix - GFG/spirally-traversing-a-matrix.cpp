//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(vector<vector<int>> a, int n, int m) 
{
   
   vector<int>v;
   int top = 0; int bot = n-1;
   int l =0; int r= m-1;
   while(top<=bot && l<=r)
   {
       for(int i=l ;i<=r; i++)
       {
           v.push_back(a[top][i]);
       }
       top++;
       if(top>bot)
       break;
       for(int i = top ; i<=bot ; i++)
       {
           v.push_back(a[i][r]);
       }
       r--;
       if(r<l)
       break;
       for(int i=r; i>=l ; i--)
       {
           v.push_back(a[bot][i]);
       }
       bot--;
       if(bot<top)
       break;
       for(int i =bot ; i>=top ; i--)
       {
           v.push_back(a[i][l]);
       }
       l++;
       if(l>r)
       break;
   }
   
   return v;
      
       
      
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends