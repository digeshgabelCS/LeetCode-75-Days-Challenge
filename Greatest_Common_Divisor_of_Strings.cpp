#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return ""; // Check if they can form a common string
        int gcdLength = gcd(str1.size(), str2.size()); // Calculate GCD of lengths
        return str1.substr(0, gcdLength); // Return the substring of length GCD
    }
private:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a; // Return GCD
    }
};
int main() {
    Solution sol;
    string str1 = "ABCABC";
    string str2 = "ABC";
    
    string result = sol.gcdOfStrings(str1, str2);
    cout << "GCD of strings: " << result << endl; // Output should be "ABC"

    return 0;
}