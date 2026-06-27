#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>>& arr) {
    int n = arr.size();

    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if (arr[i][j] == 1) {
            // i knows j, so i cannot be celebrity
            s.push(j);
        } else {
            // i does not know j, so j cannot be celebrity
            s.push(i);
        }
    }

    // Potential celebrity
    int celeb = s.top();

    // Step 3: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != celeb &&
            (arr[celeb][i] == 1 || arr[i][celeb] == 0)) {
            return -1;
        }
    }

    return celeb;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int ans = celebrity(arr);

    if (ans == -1)
        cout << "No Celebrity Found";
    else
        cout << "Celebrity is Person " << ans;

    return 0;
}