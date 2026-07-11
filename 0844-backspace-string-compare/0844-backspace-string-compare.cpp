class Solution {
public:

    string buildString(string str) {

        stack<char> st;

        for (char ch : str) {

            if (ch == '#') {

                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(ch);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool backspaceCompare(string s, string t) {

        return buildString(s) == buildString(t);
    }
};
