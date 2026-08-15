class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int maxcount=1;
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};