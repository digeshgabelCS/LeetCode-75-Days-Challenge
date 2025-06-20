#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0, currentCount = 0;
        
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                currentCount++;
            }
        }
        maxCount = currentCount;
        
        for (int i = k; i < s.length(); ++i) {
            if (vowels.count(s[i])) {
                currentCount++;
            }
            if (vowels.count(s[i - k])) {
                currentCount--;
            }
            maxCount = max(maxCount, currentCount);
        }
        
        return maxCount;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.maxVowels(s, k);
    cout << "Maximum number of vowels in any substring of length " << k << ": " << result << endl;

    return 0;
}