#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> freq1, freq2;
        unordered_set<char> set1, set2;

        // Count character frequencies and unique characters for both strings
        for (char c : word1) {
            freq1[c]++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c]++;
            set2.insert(c);
        }

        // Check if both have the same unique characters
        if (set1 != set2) return false;

        // Collect frequencies into vectors
        vector<int> counts1, counts2;
        for (auto& p : freq1) counts1.push_back(p.second);
        for (auto& p : freq2) counts2.push_back(p.second);

        // Sort and compare frequencies
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};

int main() {
    Solution sol;
    
    string word1, word2;

    cout << "Enter first string: ";
    cin >> word1;

    cout << "Enter second string: ";
    cin >> word2;

    bool result = sol.closeStrings(word1, word2);

    if (result)
        cout << "The strings are close." << endl;
    else
        cout << "The strings are not close." << endl;

    return 0;
}