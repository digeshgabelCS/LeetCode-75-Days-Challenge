#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Class to find all valid combinations of k numbers that sum to n
 *        using numbers from 1 to 9, with each number used at most once.
 */
class Solution {
public:
    /**
     * @param k Number of integers in each combination
     * @param n Target sum
     * @return A list of all unique combinations of k numbers that sum to n
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }

private:
    /**
     * @brief Helper function to perform backtracking.
     *
     * @param start Starting number for this step
     * @param k Remaining number of elements to select
     * @param n Remaining sum to achieve
     * @param current Current combination being formed
     * @param result 
     */
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }
        if (k == 0 || n < 0) return;

        for (int i = start; i <= 9; ++i) {
            current.push_back(i);                        
            backtrack(i + 1, k - 1, n - i, current, result); 
            current.pop_back();                          
        }
    }
};

int main() {
    Solution solution;

    int k = 3;
    int n = 7;

    vector<vector<int>> result = solution.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers that sum to " << n << ":\n";
    for (const auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}