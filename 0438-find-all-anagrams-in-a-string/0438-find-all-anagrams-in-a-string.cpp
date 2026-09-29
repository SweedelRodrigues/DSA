class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) {
            return ans;
        }
        unordered_map<char, int> pfreq;
        unordered_map<char, int> wfreq;
        for (char c : p) {
            pfreq[c]++;
        }
        for (int i = 0; i < p.size(); i++) {
            wfreq[s[i]]++;
        }
        if (pfreq == wfreq) {
            ans.push_back(0);
        }
        for (int i = p.size(); i < s.size(); i++) {
            char outgoing = s[i - p.size()];

            wfreq[outgoing]--;

            if (wfreq[outgoing] == 0) {
                wfreq.erase(outgoing);
            }
            wfreq[s[i]]++;
            if (wfreq == pfreq) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};