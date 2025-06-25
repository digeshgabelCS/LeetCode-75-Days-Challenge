#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1, diff2;

        // Find elements in set1 not in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);
            }
        }

        // Find elements in set2 not in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);
            }
        }

        return {diff1, diff2};
    }
};

// Helper function to print a 2D vector
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    cout << "Result: ";
    printResult(result);

    return 0;
}