#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back(); // remove closest left character
                }
            } else {
                result.push_back(c); // add normal character
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s;

    // Input string from user
    cout << "Enter the string with stars (*): ";
    cin >> s;

    // Call the function and display result
    string finalResult = solution.removeStars(s);
    cout << "Result after removing stars: " << finalResult << endl;

    return 0;
}