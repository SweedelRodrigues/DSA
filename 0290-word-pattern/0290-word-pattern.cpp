class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Split the string into words
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        // Number of pattern characters and words must match
        if (pattern.length() != words.size())
            return false;

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        for (int i = 0; i < pattern.length(); i++) {

            // Check pattern -> word mapping
            if (m1.find(pattern[i]) != m1.end()) {
                if (m1[pattern[i]] != words[i])
                    return false;
            }

            // Check word -> pattern mapping
            if (m2.find(words[i]) != m2.end()) {
                if (m2[words[i]] != pattern[i])
                    return false;
            }

            // Store mappings
            m1[pattern[i]] = words[i];
            m2[words[i]] = pattern[i];
        }

        return true;
    }
};
