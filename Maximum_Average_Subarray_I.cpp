#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0, windowSum = 0;
        
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }
        maxSum = windowSum;

        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = solution.findMaxAverage(nums, k);
    cout << "Maximum average of subarray of length " << k << " is: " << result << endl;

    return 0;
}