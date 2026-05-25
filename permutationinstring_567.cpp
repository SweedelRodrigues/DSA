#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    // Compare both frequency arrays
    bool isFreqSame(int freq1[], int freq2[]) {

        for(int i = 0; i < 26; i++) {

            if(freq1[i] != freq2[i]) {

                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};

        // Store frequency of s1
        for(int i = 0; i < s1.length(); i++) {

            int idx = s1[i] - 'a';

            freq[idx]++;
        }

        int windowSize = s1.length();

        // Sliding window on s2
        for(int i = 0; i < s2.length(); i++) {

            int windIdx = 0;

            int idx = i;

            int windFreq[26] = {0};

            // Build current window frequency
            while(windIdx < windowSize &&
                  idx < s2.length()) {

                windFreq[s2[idx] - 'a']++;

                windIdx++;
                idx++;
            }

            // Compare frequencies
            if(isFreqSame(freq, windFreq)) {

                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    bool ans = obj.checkInclusion(s1, s2);

    if(ans) {

        cout << "Permutation Exists" << endl;

    } else {

        cout << "Permutation Does NOT Exist" << endl;
    }

    return 0;
}