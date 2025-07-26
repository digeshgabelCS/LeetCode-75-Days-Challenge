#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);

        // Create pairs: (nums2[i], nums1[i])
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        // Sort pairs in descending order of nums2
        sort(pairs.rbegin(), pairs.rend());

        // Min-heap to maintain top k elements from nums1
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, result = 0;

        for (int i = 0; i < n; ++i) {
            int currNum2 = pairs[i].first;
            int currNum1 = pairs[i].second;

            // Add current nums1 value to heap and sum
            minHeap.push(currNum1);
            sum += currNum1;

            // Remove smallest if we exceed size k
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // If we have exactly k elements, calculate score
            if (minHeap.size() == k) {
                result = max(result, sum * 1LL * currNum2);
            }
        }

        return result;
    }
};

// Optional main function for local testing
int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 3, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    int k = 3;

    cout << "Max Score: " << sol.maxScore(nums1, nums2, k) << endl;
    return 0;
}
