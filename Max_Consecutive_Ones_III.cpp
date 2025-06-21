#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;

    int result = sol.longestOnes(nums, k);

    cout << "Maximum consecutive 1's with at most " << k << " zero flips: " << result << endl;

    return 0;
}