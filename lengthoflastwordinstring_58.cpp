#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int i = s.length() - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    int count = 0;

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Length of last word: " << lengthOfLastWord(s) << endl;

    return 0;
}