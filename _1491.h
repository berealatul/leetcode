#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        long long salarySum = 0;
        for (auto& val : salary) {
            salarySum += val;
            minSalary = min(minSalary, val);
            maxSalary = max(maxSalary, val);
        }

        salarySum -= minSalary;
        salarySum -= maxSalary;

        return salarySum / static_cast<double>(salary.size() - 2);
    }
};