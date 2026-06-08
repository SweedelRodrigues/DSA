#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    int n = nums.size();

    if(n <= 2)
        return n;

    int k = 2;

    for(int i = 2; i < n; i++) {

        if(nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "Length after removing duplicates: " << k << endl;

    cout << "Modified array: ";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}