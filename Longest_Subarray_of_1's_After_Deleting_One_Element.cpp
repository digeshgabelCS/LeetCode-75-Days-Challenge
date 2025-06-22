#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                ++zeroCount;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    --zeroCount;
                }
                ++left;
            }

            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};
    int result = solution.longestSubarray(nums);

    cout << "Length of longest subarray of 1's after deleting one element: " << result << endl;

    return 0;
}