#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    string reverseWords(string s) {

        int n = s.length();

        string ans = "";

        // Reverse entire string
        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {

            string words = "";

            // Extract one word
            while(i < n && s[i] != ' ') {

                words += s[i];
                i++;
            }

            // Reverse individual word
            reverse(words.begin(), words.end());

            // Avoid extra spaces
            if(words.length() > 0) {

                ans += " " + words;
            }
        }

        // Remove leading space
        return ans.substr(1);
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";

    getline(cin, s);

    string ans = obj.reverseWords(s);

    cout << "Reversed Words String: " << ans << endl;

    return 0;
}