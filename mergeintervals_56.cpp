#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    if(intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    res.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++)
    {
        vector<int> current = intervals[i];

        if(current[0] <= res.back()[1])
        {
            res.back()[1] = max(res.back()[1], current[1]);
        }
        else
        {
            res.push_back(current);
        }
    }

    return res;
}

int main()
{
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter start and end of each interval:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "\nMerged Intervals:\n";

    for(auto interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}