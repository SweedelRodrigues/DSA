class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for(auto it : freq) {
            int f = it.second;

            ans += (f / 2) * 2;

            if(f % 2 == 1)
                hasOdd = true;
        }

        if(hasOdd)
            ans++;

        return ans;
    }
};