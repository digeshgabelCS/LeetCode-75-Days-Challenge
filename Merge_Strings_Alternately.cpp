#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int n1 = word1.size(), n2 = word2.size();

        // Add alternating characters
        while (i < n1 && j < n2) {
            result += word1[i++];
            result += word2[j++];
        }

        // Append remaining characters from word1, if any
        while (i < n1) {
            result += word1[i++];
        }

        // Append remaining characters from word2, if any
        while (j < n2) {
            result += word2[j++];
        }

        return result;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "pqrst";
    
    string merged = sol.mergeAlternately(word1, word2);
    cout << "Merged string: " << merged << endl;

    return 0;
}