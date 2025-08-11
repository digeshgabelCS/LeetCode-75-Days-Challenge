#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        // cash: max profit if we don't have stock at the end of the day
        // hold: max profit if we have stock at the end of the day
        int cash = 0;
        int hold = -prices[0]; // initially buy stock on day 0

        for (int i = 1; i < n; ++i) {
            // store previous cash before updating
            int prevCash = cash;

            // Update cash: sell stock today or keep previous cash
            cash = max(cash, hold + prices[i] - fee);

            // Update hold: buy stock today or keep holding
            hold = max(hold, prevCash - prices[i]);
        }

        return cash;
    }
};