class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int minprod=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int oldmax=maxprod;
            int oldmin=minprod;
            maxprod=max({nums[i],(oldmax*nums[i]),(oldmin*nums[i])});
            minprod=min({nums[i],(oldmax*nums[i]),(oldmin*nums[i])});
            ans=max(ans,maxprod);
        }
        return ans;
    }
};