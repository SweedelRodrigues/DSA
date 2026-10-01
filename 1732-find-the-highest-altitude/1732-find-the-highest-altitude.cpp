class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0;
        int maxaltitude=0;
        for(int i=0;i<gain.size();i++)
        {
            altitude+=gain[i];
            maxaltitude=max(maxaltitude,altitude);
        }
        return maxaltitude;
    }
};