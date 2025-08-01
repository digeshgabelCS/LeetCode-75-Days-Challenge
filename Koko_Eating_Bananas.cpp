#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid)) {
                result = mid;      
                right = mid - 1;
            } else {
                left = mid + 1;   
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int minSpeed = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << minSpeed << endl;

    return 0;
}