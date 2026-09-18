class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int len = 1; len <= s.size() / 2; len++) {

            if(s.size() % len != 0)
                continue;

            bool valid = true;

            for(int i = len; i < s.size(); i++) {
                if(s[i] != s[i - len]) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                return true;
        }

        return false;
    }
};