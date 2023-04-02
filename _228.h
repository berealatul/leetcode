#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;

        int previous;
        bool previousExist = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!previousExist) {
                previous = nums[i];
                previousExist = true;
                continue;
            }

            if (previousExist && (static_cast<long>(nums[i]) - nums[i - 1]) > 1) {
                if (previous == nums[i - 1]) answer.push_back(to_string(previous));
                else answer.push_back(to_string(previous) + "->" + to_string(nums[i - 1]));
                previous = nums[i];
            }
        }

        if (previousExist) {
            if (nums.back() == previous) answer.push_back(to_string(nums.back()));
            else answer.push_back(to_string(previous) + "->" + to_string(nums.back()));
        }

        return answer;
    }
};