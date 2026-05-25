#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        // Dutch National Flag Algorithm
        while(mid <= high) {

            // If element is 0
            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // If element is 1
            else if(nums[mid] == 1) {

                mid++;
            }

            // If element is 2
            else {

                swap(nums[high], nums[mid]);

                high--;
            }
        }
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2,0,2,1,1,0};

    obj.sortColors(nums);

    cout << "Sorted Colors Array: ";

    for(int val : nums) {

        cout << val << " ";
    }

    cout << endl;

    return 0;
}