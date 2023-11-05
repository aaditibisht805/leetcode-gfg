//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
/*class Solution {
  public:
    string findSum(string x, string y) {
        string ast="";
        vector<char>v;int c=0;
      int n = x.size()-1;
      int m = y.size()-1;
      int i = n; int j =m;
      while(i>=0 && j >=0)
      {
          int a = x[i]-'0';
          int b = y[j]-'0';
          int sum = a+b+c;
          if(sum>=10)
          c= sum/10;
          char ma = '0'+sum;
          v.push_back(ma);
          i--;
          j--;
          
      }
      while(i>=0)
      {
          v.push_back(x[i]);
          i--;
      }
      while(j>=0)
      {
          v.push_back(y[j]);
          j--;
      }
     for(int i=v.size()-1;i>=0; i--)
     {
         ast+=v[i];
     }
     return ast;
      
    }
};*/
class Solution {
public:
    string findSum(string x, string y) {
        string result = "";int c=0;
        vector<char> v;
        int carry = 0;
        int n = x.size();
        int m = y.size();
        int i = n - 1, j = m - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int a = (i >= 0) ? x[i] - '0' : 0;
            int b = (j >= 0) ? y[j] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            char ma = '0' + (sum % 10);
            v.push_back(ma);

            if (i >= 0) i--;
            if (j >= 0) j--;
        }
        
        for (int i = v.size() - 1; i >= 0; i--) {
          result+=v[i];
        }
         size_t nonZeroPos = result.find_first_not_of('0');
        if (nonZeroPos != string::npos) {
            result = result.substr(nonZeroPos);
        } else {
            // If the result is all zeros, set it to "0"
            result = "0";
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends