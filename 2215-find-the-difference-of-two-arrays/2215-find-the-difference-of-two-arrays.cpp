class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        vector<int>a;
        vector<int>b;
        for(int num:s1)
        {
            if(s2.find(num)==s2.end())
            {
                a.push_back(num);
            }
        }
        for(int num:s2)
        {
            if(s1.find(num)==s1.end())
            {
                b.push_back(num);
            }
        }
        return {a,b};
    }
};