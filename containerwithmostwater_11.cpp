#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {

        int maxWater = 0;

        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp) {

            int w = rp - lp;

            int ht = min(height[lp], height[rp]);

            int currWater = w * ht;

            maxWater = max(maxWater, currWater);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = obj.maxArea(height);

    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}