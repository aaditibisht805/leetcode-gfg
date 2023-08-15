class Solution {
public:
    int maxProfit(vector<int>& a) {

  int profit =0;
  int mini = a[0];
  for(int i=1;i< a.size();i++)
  {
    int   diff= a[i]-mini;
      profit = max (profit , diff);
      mini = min(mini, a[i]);

  }
  return profit ;
    }
};