//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   /* vector<vector<int>>floodFill(vector<vector<int>>&a, int sr, int sc, int n) {
      queue<pair<int,int>>q;
      vector<vector<int>>v=a ;
      
      int na = a.size();
      int m = a[0].size();
      q.push({sr, sc});
      while(!q.empty())
      {
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
           
              if(col-1>=0 && a[row][col]==a[row][col-1])
              {  v[row][col-1]=n;
                 q.push({row, col-1});
                 
              }
              if(col+1<m && a[row][col]==a[row][col+1] )
              {  v[row][col+1]=n;
                 q.push({row, col+1});
                 
              }
              if(row+1<na && a[row][col]==a[row+1][col])
              {  v[row+1][col]=n;
                 q.push({row+1, col});
                 
              }
              if(row-1>=0 && a[row][col]==a[row-1][col])
              {  v[row-1][col]=n;
                 q.push({row-1, col});
                 
              }
              v[row][col]=n;
             
         
         
      }
      return v;
       
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int n) {
    queue<pair<int, int>> q;
    vector<vector<int>> v = a;
    int na = a.size();
    int m = a[0].size();
    int startValue = a[sr][sc]; // Store the starting value for comparison
    q.push({sr, sc});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Check if the current cell has the same value as the starting cell
        if (a[row][col] == startValue) {
            // Update the result matrix and enqueue neighboring cells
            v[row][col] = n;

            // Check and enqueue left neighbor
            if (col - 1 >= 0 && a[row][col - 1] == startValue) {
                q.push({row, col - 1});
            }
            // Check and enqueue right neighbor
            if (col + 1 < m && a[row][col + 1] == startValue) {
                q.push({row, col + 1});
            }
            // Check and enqueue upper neighbor
            if (row - 1 >= 0 && a[row - 1][col] == startValue) {
                q.push({row - 1, col});
            }
            // Check and enqueue lower neighbor
            if (row + 1 < na && a[row + 1][col] == startValue) {
                q.push({row + 1, col});
            }
        }
    }
    return v;*/
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int n) {
    queue<pair<int, int>> q;
    vector<vector<int>> v = a;
    int na = a.size();
    int m = a[0].size();
    int startValue = a[sr][sc]; // Store the starting value for comparison
    q.push({sr, sc});

    // Create a visited matrix initialized to false
    vector<vector<bool>> visited(na, vector<bool>(m, false));
    
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        
        if (a[row][col] == startValue && !visited[row][col]) {
            // Update the result matrix and mark the cell as visited
            v[row][col] = n;
            visited[row][col] = true;

            // Check and enqueue left neighbor
            if (col - 1 >= 0) {
                q.push({row, col - 1});
            }
            // Check and enqueue right neighbor
            if (col + 1 < m) {
                q.push({row, col + 1});
            }
            // Check and enqueue upper neighbor
            if (row - 1 >= 0) {
                q.push({row - 1, col});
            }
            // Check and enqueue lower neighbor
            if (row + 1 < na) {
                q.push({row + 1, col});
            }
        }
    }
    return v;
}



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends