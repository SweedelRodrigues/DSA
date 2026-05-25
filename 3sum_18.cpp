#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int tar) {

        vector<vector<int>> ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Skip duplicate i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i + 1; j < n; ) {

                int p = j + 1;
                int q = n - 1;

                while(p < q) {

                    long long sum =
                        (long long)nums[i] +
                        (long long)nums[j] +
                        (long long)nums[p] +
                        (long long)nums[q];

                    // Sum smaller than target
                    if(sum < tar) {

                        p++;

                    }

                    // Sum greater than target
                    else if(sum > tar) {

                        q--;

                    }

                    // Quadruplet found
                    else {

                        ans.push_back(
                            {nums[i], nums[j], nums[p], nums[q]}
                        );

                        p++;
                        q--;

                        // Skip duplicate p
                        while(p < q && nums[p] == nums[p-1])
                            p++;

                        // Skip duplicate q
                        while(p < q && nums[q] == nums[q+1])
                            q--;
                    }
                }

                j++;

                // Skip duplicate j
                while(j < n && nums[j] == nums[j-1])
                    j++;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 0, -1, 0, -2, 2};

    int target = 0;

    vector<vector<int>> result = obj.fourSum(nums, target);

    cout << "Unique Quadruplets are:\n";

    for(auto quad : result) {

        cout << "[ ";

        for(auto val : quad) {
            cout << val << " ";
        }

        cout << "]\n";
    }

    return 0;
}