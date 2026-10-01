class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());

        int sum = 0;

        for (int num : salary) {
            sum += num;
        }

        int finalSum = sum - minSalary - maxSalary;

        return static_cast<double>(finalSum) / (salary.size() - 2);
    }
};