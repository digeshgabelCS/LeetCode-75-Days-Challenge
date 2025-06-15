#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        // Fill the rest of the array with zeroes
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}