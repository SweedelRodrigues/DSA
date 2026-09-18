class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";

        for(char ch : s) {
            if(ch != '-')
                temp += toupper(ch);
        }

        int first = temp.size() % k;

        string ans = "";

        if(first > 0) {
            ans = temp.substr(0, first);
        }

        for(int i = first; i < temp.size(); i++) {
            if((i - first) % k == 0) {
                if(!ans.empty())
                    ans += '-';
            }

            ans += temp[i];
        }

        return ans;
    }
};