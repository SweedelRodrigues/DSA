#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int binsearch(vector<int>& arr, int tar, int st, int end) {

        if (st <= end) {

            int mid = st + (end - st) / 2;

            if (arr[mid] == tar)
                return mid;

            else if (arr[mid] <= tar) {
                return binsearch(arr, tar, mid + 1, end);
            }

            else {
                return binsearch(arr, tar, st, mid - 1);
            }
        }

        return -1;
    }

    int search(vector<int>& arr, int tar) {

        return binsearch(arr, tar, 0, arr.size() - 1);
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int result = obj.search(arr, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}