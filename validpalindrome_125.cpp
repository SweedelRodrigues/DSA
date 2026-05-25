#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:

    // Check if character is alphanumeric
    bool isAlphaNum(char ch) {

        return isalnum(ch);
    }

    bool isPalindrome(string s) {

        int st = 0;
        int end = s.length() - 1;

        while(st < end) {

            // Skip non-alphanumeric from left
            if(!isAlphaNum(s[st])) {

                st++;
                continue;
            }

            // Skip non-alphanumeric from right
            if(!isAlphaNum(s[end])) {

                end--;
                continue;
            }

            // Compare after converting to lowercase
            if(tolower(s[st]) != tolower(s[end])) {

                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";

    getline(cin, s);

    bool ans = obj.isPalindrome(s);

    if(ans) {

        cout << "Palindrome String" << endl;

    } else {

        cout << "Not a Palindrome String" << endl;
    }

    return 0;
}