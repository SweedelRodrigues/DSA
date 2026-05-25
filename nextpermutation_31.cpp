#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void nextPermutation(vector<int>& A) {

        int n = A.size();

        int pivot = -1;

        // Step 1: Find pivot
        for(int i = n - 2; i >= 0; i--) {

            if(A[i] < A[i + 1]) {

                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found
        if(pivot == -1) {

            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find next greater element
        for(int i = n - 1; i > pivot; i--) {

            if(A[i] > A[pivot]) {

                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: Reverse right portion
        int i = pivot + 1;
        int j = n - 1;

        while(i <= j) {

            swap(A[i], A[j]);

            i++;
            j--;
        }
    }
};

int main() {

    Solution obj;

    vector<int> A = {1, 2, 3};

    obj.nextPermutation(A);

    cout << "Next Permutation: ";

    for(int val : A) {

        cout << val << " ";
    }

    cout << endl;

    return 0;
}