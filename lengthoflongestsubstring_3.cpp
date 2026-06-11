#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> st;

    int left = 0;
    int right = 0;
    int maxLen = 0;

    while(right < s.size())
    {
        while(st.count(s[right]))
        {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        maxLen = max(maxLen, right - left + 1);

        right++;
    }

    return maxLen;
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}