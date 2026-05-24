#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Skip duplicate elements for i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Sum greater than 0
                if(sum > 0) {

                    k--;

                }

                // Sum smaller than 0
                else if(sum < 0) {

                    j++;

                }

                // Triplet found
                else {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate j values
                    while(j < k && nums[j] == nums[j-1])
                        j++;

                    // Skip duplicate k values
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Unique Triplets are:\n";

    for(auto triplet : result) {

        cout << "[ ";

        for(auto val : triplet) {
            cout << val << " ";
        }

        cout << "]\n";
    }

    return 0;
}