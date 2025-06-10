#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        // Set of vowels for quick lookup
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.length() - 1;

        // Two-pointer approach
        while (left < right) {
            // Move left pointer to the next vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            // Move right pointer to the previous vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }

            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s;

    // Input string from user
    cout << "Enter a string: ";
    getline(cin, s);

    // Call the reverseVowels function and output the result
    string result = sol.reverseVowels(s);
    cout << "String after reversing vowels: " << result << endl;

    return 0;
}