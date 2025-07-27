#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long total = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> leftHeap, rightHeap;

        for (int i = 0; i < candidates && left <= right; ++i) {
            leftHeap.emplace(costs[left], left);
            ++left;
        }
        for (int i = 0; i < candidates && left <= right; ++i) {
            rightHeap.emplace(costs[right], right);
            --right;
        }

        for (int hire = 0; hire < k; ++hire) {
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                total += leftHeap.top().first;
                leftHeap.pop();
                if (left <= right) {
                    leftHeap.emplace(costs[left], left);
                    ++left;
                }
            } else {
                total += rightHeap.top().first;
                rightHeap.pop();
                if (left <= right) {
                    rightHeap.emplace(costs[right], right);
                    --right;
                }
            }
        }

        return total;
    }
};

int main() {
    Solution sol;
    vector<int> costs = {3, 2, 7, 7, 1, 2};
    int k = 3;
    int candidates = 2;

    long long result = sol.totalCost(costs, k, candidates);
    cout << "Total cost to hire " << k << " workers: " << result << endl;

    return 0;
}