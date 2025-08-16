#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; 
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prevEnd) {
                count++;
                prevEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(intervals1) << endl;

    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    cout << sol.eraseOverlapIntervals(intervals2) << endl; 

    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    cout << sol.eraseOverlapIntervals(intervals3) << endl;  

    return 0;
}