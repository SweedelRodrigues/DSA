class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {

                if (dp[i] && words.count(s.substr(i, j - i))) {
                    dp[j] = true;
                }
            }
        }

        return dp[s.length()];
    }
};