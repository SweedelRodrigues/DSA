#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int compress(vector<char>& chars) {

        int n = chars.size();

        int idx = 0;

        for(int i = 0; i < n; i++) {

            char ch = chars[i];

            int count = 0;

            // Count consecutive same characters
            while(i < n && chars[i] == ch) {

                count++;
                i++;
            }

            // Single occurrence
            if(count == 1) {

                chars[idx++] = ch;
            }

            // Multiple occurrences
            else {

                chars[idx++] = ch;

                string str = to_string(count);

                for(char dig : str) {

                    chars[idx++] = dig;
                }
            }

            i--;
        }

        // Resize vector to compressed length
        chars.resize(idx);

        return idx;
    }
};

int main() {

    Solution obj;

    vector<char> chars = {
        'a','a','b','b','c','c','c'
    };

    int len = obj.compress(chars);

    cout << "Compressed Length: " << len << endl;

    cout << "Compressed Array: ";

    for(char ch : chars) {

        cout << ch << " ";
    }

    cout << endl;

    return 0;
}