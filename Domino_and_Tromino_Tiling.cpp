#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    cout << "Number of tilings for 2 x " << n << " board: " << sol.numTilings(n) << endl;
    return 0;
}