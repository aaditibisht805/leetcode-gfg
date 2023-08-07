class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int j=0;
        for(auto x: s)
        {
            if(x >0)
            {
                j++;
                if(x!=j)
                return j;
            }
        }
        return j+1;
        
    }
};