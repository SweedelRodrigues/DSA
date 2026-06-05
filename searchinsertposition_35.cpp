#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if(nums[i] >= target) {
            return i;
        }
    }

    return n;
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "Insert Position = " << searchInsert(nums, target);

    return 0;
}