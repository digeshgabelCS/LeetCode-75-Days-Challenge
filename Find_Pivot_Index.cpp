#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Check if left sum equals right sum
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        
        // If no pivot index found
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    
    Solution sol;
    int pivot = sol.pivotIndex(nums);
    
    // Output result
    if (pivot != -1) {
        cout << "Pivot index is: " << pivot << endl;
    } else {
        cout << "No pivot index found." << endl;
    }

    return 0;
}