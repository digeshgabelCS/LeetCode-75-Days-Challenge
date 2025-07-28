#include <iostream>
using namespace std;

int pickedNumber = 42;

int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1; 
    }
};

int main() {
    Solution sol;
    int n = 100;
    int guessed = sol.guessNumber(n);
    cout << "Guessed Number: " << guessed << endl;
    return 0;
}