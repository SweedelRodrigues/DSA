#include <iostream>

using namespace std;

class Solution {
public:

    double myPow(double x, int n) {

        long binForm = n;
        double ans = 1;

        if (n < 0) {
            x = 1 / x;
            binForm = -binForm;
        }

        while (binForm > 0) {

            if (binForm % 2 == 1) {
                ans *= x;
            }

            x *= x;
            binForm /= 2;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    double result = obj.myPow(x, n);

    cout << "Result = " << result << endl;

    return 0;
}