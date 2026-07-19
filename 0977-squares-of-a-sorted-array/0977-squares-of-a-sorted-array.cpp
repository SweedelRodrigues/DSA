class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size()-1,k=nums.size()-1;
        vector<int>ans(nums.size());
        while(left<=right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[k]=nums[left]*nums[left];
                left++;
                k--;
            }else
            {

                ans[k]=nums[right]*nums[right];
                right--;
                k--;
            }
        }
        return ans;
    }
};