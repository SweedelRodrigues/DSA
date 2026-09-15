class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> result;

        for(int i = 0; i < nums1.size(); i++) {
            set1.insert(nums1[i]);
        }

        for(int i = 0; i < nums2.size(); i++) {
            if(set1.count(nums2[i])) {
                result.insert(nums2[i]);
            }
        }

       vector<int> ans(result.begin(), result.end());
       return ans;
    }
};