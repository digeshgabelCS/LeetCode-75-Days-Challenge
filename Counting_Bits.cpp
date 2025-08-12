#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.countBits(n);

    cout << "Binary 1's count for 0 to " << n << ":\n";
    for (int i = 0; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}