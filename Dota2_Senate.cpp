#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;

        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();

            if (r_index < d_index) {
                radiant.push(r_index + n);
            } else {
                dire.push(d_index + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    Solution solution;
    string senate;

    cout << "Enter the senate string (R for Radiant, D for Dire): ";
    cin >> senate;

    string result = solution.predictPartyVictory(senate);

    cout << "The winning party is: " << result << endl;

    return 0;
}