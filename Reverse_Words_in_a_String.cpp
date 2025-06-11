#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);    
        string word;
        vector<string> words;

        // Split the string into words, ignoring extra spaces
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the vector of words
        reverse(words.begin(), words.end());

        // Concatenate the words with a single space
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    string s1 = "  hello   world!  ";
    string s2 = "  the  sky   is blue  ";
    string s3 = "a good   example";

    cout << "Test 1: '" << sol.reverseWords(s1) << "'" << endl;
    cout << "Test 2: '" << sol.reverseWords(s2) << "'" << endl;
    cout << "Test 3: '" << sol.reverseWords(s3) << "'" << endl;

    return 0;
}