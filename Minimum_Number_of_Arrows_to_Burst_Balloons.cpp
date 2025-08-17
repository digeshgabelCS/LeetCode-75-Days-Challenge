#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int arrows = 1; 
        long long lastArrow = points[0][1]; // Place arrow at the end of the first balloon

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > lastArrow) {
                // Need a new arrow if the balloon starts after lastArrow
                arrows++;
                lastArrow = points[i][1];
            }
        }

        return arrows;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << "Minimum arrows needed: " << sol.findMinArrowShots(points) << endl;

    // Another test case
    vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};
    cout << "Minimum arrows needed: " << sol.findMinArrowShots(points2) << endl;

    // Another test case
    vector<vector<int>> points3 = {{1,2},{2,3},{3,4},{4,5}};
    cout << "Minimum arrows needed: " << sol.findMinArrowShots(points3) << endl;

    return 0;
}
