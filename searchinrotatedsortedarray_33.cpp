#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int search(vector<int>& A, int tar) {

        int st = 0;
        int end = A.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (A[mid] == tar) {
                return mid;
            }

            // Left half is sorted
            if (A[st] <= A[mid]) {

                if (A[st] <= tar && tar <= A[mid]) {
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (A[mid] <= tar && tar <= A[end]) {
                    st = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter rotated sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    int result = obj.search(arr, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    }
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}