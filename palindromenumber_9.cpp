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

    bool isPalindrome(int n) {

        // Negative numbers are not palindrome
        if(n < 0)
            return false;

        int revNum = reverse(n);

        return n == revNum;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number: ";
    cin >> n;

    if(obj.isPalindrome(n)) {

        cout << n << " is a Palindrome Number" << endl;

    } else {

        cout << n << " is NOT a Palindrome Number" << endl;
    }

    return 0;
}