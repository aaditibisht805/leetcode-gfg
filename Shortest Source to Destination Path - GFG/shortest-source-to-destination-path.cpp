//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
            if(!A[0][0])
        {
            return -1;
        }
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        int ans = INT_MAX;
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int val = q.front()[2];
            
            q.pop();
            
            if(x == X && y == Y)
            {
                ans = min(ans, val);
                continue;
            }
            else
            {
                for(int i = 0; i < 4; i++)
                {
                    int nRow = x + delRow[i];
                    int nCol = y + delCol[i];
                    
                    if(nRow >= 0 && nRow < N && nCol >= 0 && nCol < M && !vis[nRow][nCol] && A[nRow][nCol])
                    {
                        vis[nRow][nCol] = true;
                        q.push({nRow, nCol, val + 1});
                    }
                }
            }
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends