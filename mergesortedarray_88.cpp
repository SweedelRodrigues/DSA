#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void merge(vector<int>& A, int m,
               vector<int>& B, int n) {

        int idx = m + n - 1;

        int i = m - 1;
        int j = n - 1;

        // Merge from back
        while(i >= 0 && j >= 0) {

            if(A[i] >= B[j]) {

                A[idx] = A[i];

                idx--;
                i--;
            }

            else {

                A[idx] = B[j];

                idx--;
                j--;
            }
        }

        // Remaining elements of B
        while(j >= 0) {

            A[idx--] = B[j--];
        }
    }
};

int main() {

    Solution obj;

    vector<int> A = {1,2,3,0,0,0};

    int m = 3;

    vector<int> B = {2,5,6};

    int n = 3;

    obj.merge(A, m, B, n);

    cout << "Merged Array: ";

    for(int val : A) {

        cout << val << " ";
    }

    cout << endl;

    return 0;
}