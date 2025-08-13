#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        for (int i = 0; i < 32; ++i) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            
            if ((bitA | bitB) == bitC) {
                continue;
            }
            
            if (bitC == 1) {
                flips += 1;
            } else {
                flips += bitA + bitB; 
            }
        }
        
        return flips;
    }
};

int main() {
    Solution sol;
    int a, b, c;
    
    cout << "Enter values of a, b, c: ";
    cin >> a >> b >> c;
    
    int result = sol.minFlips(a, b, c);
    cout << "Minimum flips required: " << result << endl;
    
    return 0;
}