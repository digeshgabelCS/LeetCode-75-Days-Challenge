#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> rowMap;
        int count = 0;

        auto vecToStr = [](const vector<int>& vec) {
            string s;
            for (int num : vec) {
                s += to_string(num) + ",";
            }
            return s;
        };

        for (int i = 0; i < n; ++i) {
            string rowStr = vecToStr(grid[i]);
            rowMap[rowStr]++;
        }

        for (int j = 0; j < n; ++j) {
            vector<int> colVec;
            for (int i = 0; i < n; ++i) {
                colVec.push_back(grid[i][j]);
            }
            string colStr = vecToStr(colVec);
            if (rowMap.count(colStr)) {
                count += rowMap[colStr];
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}
    };

    int result = sol.equalPairs(grid);
    cout << "Number of equal row and column pairs: " << result << endl;

    return 0;
}