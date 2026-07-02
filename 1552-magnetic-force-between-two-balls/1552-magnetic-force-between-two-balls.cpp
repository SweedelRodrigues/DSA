class Solution {
public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        int ans = 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int ballsPlaced = 1;
            int lastPosition = position[0];

            for (int i = 1; i < position.size(); i++) {

                if (position[i] - lastPosition >= mid) {
                    ballsPlaced++;
                    lastPosition = position[i];
                }
            }

            if (ballsPlaced >= m) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};