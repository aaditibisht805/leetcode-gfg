class Solution {
public:
 bool valid(vector<int> &nums,int mid , int n , int p )
      { int i=0; int count =0;
          while(i<n-1)
          {
                if(nums[i+1]-nums[i]<=mid)
                { 
                    count++;
                    i=i+2;

                }
                else
                i++;
          }
          return count >= p;
      }
    int minimizeMax(vector<int>& nums, int p) {
    int result , mid;

      sort(nums.begin(), nums.end());
      int n = nums.size();
      int i=0 , j= nums[n-1]- nums[0];
      while(i<=j)
      {
          int mid = (i+j)/2;
          if(valid(nums,mid, n, p))
          {
              result = mid ;
              j = mid-1;

          }
          else
          i = mid+1;
      }
      return result;
    }
};