class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            int idx = s1[i] - 'a';   // for a -> 0, b -> 1, c -> 2
            freq[idx]++;
            // we can also write as freq[s1[i] - 'a']++
        }

        int windowSize = s1.length();

        for(int i = 0; i < s2.length(); i++) {

            int windIdx = 0;
            int idx = i;

            int windFreq[26] = {0};

            while(windIdx < windowSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            if(isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }

    bool isFreqSame(int freq1[], int freq2[]) {   // O(1)
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};