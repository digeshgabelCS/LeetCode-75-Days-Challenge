#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++; 
            }
            j++; 
        }
        
        return i == m;
    }
};

int main() {
    Solution solution;
    string s, t;
    
    cout << "Enter string s (subsequence candidate): ";
    cin >> s;
    cout << "Enter string t (main string): ";
    cin >> t;
    
    // Check if s is a subsequence of t
    bool result = solution.isSubsequence(s, t);
    
    // Output result
    if (result)
        cout << "\"" << s << "\" is a subsequence of \"" << t << "\"" << endl;
    else
        cout << "\"" << s << "\" is NOT a subsequence of \"" << t << "\"" << endl;
    
    return 0;
}