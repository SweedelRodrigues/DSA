class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for (int i = 0; i < image.size(); i++) {

            int left = 0;
            int right = image[i].size() - 1;

            while (left <= right) {

                int temp = image[i][left];

                image[i][left] = 1 - image[i][right];
                image[i][right] = 1 - temp;

                left++;
                right--;
            }
        }

        return image;
    }
};