#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int peakIndexInMountainArray(vector<int>& A) {

        int st = 1;
        int end = A.size() - 2;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid;
            }

            else if (A[mid - 1] < A[mid]) {
                st = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of mountain array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = obj.peakIndexInMountainArray(arr);

    cout << "Peak index is: " << result << endl;

    return 0;
}