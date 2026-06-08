#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

    vector<int> ans;

    // Store non-zero elements
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            ans.push_back(nums[i]);
        }
    }

    // Count remaining zeros
    int rem = nums.size() - ans.size();

    // Add zeros at the end
    for(int i = 0; i < rem; i++) {
        ans.push_back(0);
    }

    // Copy answer back to original array
    nums = ans;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    moveZeroes(nums);

    cout << "Output: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}