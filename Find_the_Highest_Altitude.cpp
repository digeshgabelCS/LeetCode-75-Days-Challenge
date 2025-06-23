#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int highest = 0;
        
        for (int g : gain) {
            altitude += g;
            highest = max(highest, altitude);
        }
        
        return highest;
    }
};

int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};

    Solution sol;

    int result = sol.largestAltitude(gain);

    cout << "The highest altitude reached is: " << result << endl;

    return 0;
}