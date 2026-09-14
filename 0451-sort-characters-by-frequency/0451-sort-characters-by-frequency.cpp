class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> arr;

        for(auto p : freq) {
            arr.push_back({p.first, p.second});
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans;

        for(auto p : arr) {
            for(int i = 0; i < p.second; i++) {
                ans += p.first;
            }
        }

        return ans;
    }
};