#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {

    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(i > maxReach) {
            return false;
        }

        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
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

    if(canJump(nums)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}