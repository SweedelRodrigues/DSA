class Solution { 
public: 
    bool wordPattern(string pattern, string s) { 
        vector<string> words; 
        stringstream ss(s); 
        string word; 
        while (ss >> word) { 
            words.push_back(word); 
        } 
        if (pattern.length() != words.size()) 
            return false; 
        unordered_map<char, string> m1; 
        unordered_map<string, char> m2; 
        for (int i = 0; i < pattern.length(); i++) { 
            if (m1.find(pattern[i]) != m1.end()) { 
                if (m1[pattern[i]] != words[i]) 
                    return false; 
            } 
            if (m2.find(words[i]) != m2.end()) { 
                if (m2[words[i]] != pattern[i]) 
                    return false; 
            } 
          m1[pattern[i]] = words[i]; m2[words[i]] = pattern[i];
          } 
        return true;
        }
    };