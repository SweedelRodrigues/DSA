#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void reverseString(vector<char>& s) {

        int st = 0;
        int end = s.size() - 1;

        // Two pointer approach
        while(st < end) {

            swap(s[st++], s[end--]);
        }
    }
};

int main() {

    Solution obj;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    obj.reverseString(s);

    cout << "Reversed String: ";

    for(char ch : s) {

        cout << ch;
    }

    cout << endl;

    return 0;
}