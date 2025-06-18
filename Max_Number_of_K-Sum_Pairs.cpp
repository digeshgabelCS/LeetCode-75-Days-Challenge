#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;
            if (freq[complement] > 0) {
                operations++;
                freq[complement]--;
            } else {
                freq[num]++;
            }
        }

        return operations;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    int result = solution.maxOperations(nums, k);
    cout << "Maximum number of operations: " << result << endl;

    return 0;
}