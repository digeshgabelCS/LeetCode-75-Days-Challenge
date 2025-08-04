#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        int prev2 = cost[0]; // cost to reach step 0
        int prev1 = cost[1]; // cost to reach step 1

        for (int i = 2; i < n; ++i) {
            int current = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }

        return min(prev1, prev2);
    }
};

// Example usage
int main() {
    Solution sol;
    
    // Example 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Minimum cost: " << sol.minCostClimbingStairs(cost1) << endl;
    // Output: 15

    // Example 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost: " << sol.minCostClimbingStairs(cost2) << endl;
    // Output: 6

    return 0;
}