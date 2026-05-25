#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:

    int reverse(int n) {

        int revNum = 0;

        while(n != 0) {

            int dig = n % 10;

            // Overflow check
            if(revNum > INT_MAX / 10 ||
               revNum < INT_MIN / 10) {

                return 0;
            }

            revNum = revNum * 10 + dig;

            n = n / 10;
        }

        return revNum;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number: ";
    cin >> n;

    int ans = obj.reverse(n);

    cout << "Reversed Number: " << ans << endl;

    return 0;
}