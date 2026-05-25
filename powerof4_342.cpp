// LeetCode 342 - Power of Four
// Full code for VS Code (C++)

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfFour(n))
        cout << n << " is a Power of Four" << endl;
    else
        cout << n << " is NOT a Power of Four" << endl;

    return 0;
}