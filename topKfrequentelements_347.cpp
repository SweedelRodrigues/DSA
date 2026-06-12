#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> freq;

    for(int num : nums)
    {
        freq[num]++;
    }

    priority_queue<pair<int, int>> pq;

    for(auto it : freq)
    {
        pq.push({it.second, it.first});
    }

    vector<int> ans;

    for(int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for(int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}