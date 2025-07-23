#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;
        
        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push(make_pair(r, c));
                } else if (grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; 

        int minutes = 0;
        vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> front = q.front();
                int r = front.first;
                int c = front.second;
                q.pop();

                for (auto dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push(make_pair(nr, nc));
                        freshOranges--;
                        rottedThisMinute = true;
                    }
                }
            }

            if (rottedThisMinute) minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = solution.orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << result << endl;

    return 0;
}