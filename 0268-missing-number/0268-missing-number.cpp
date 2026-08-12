class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorsum=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            xorsum^=i;
        }
        for(int num:nums)
        {
            xorsum^=num;
        }
        return xorsum;
    }
};