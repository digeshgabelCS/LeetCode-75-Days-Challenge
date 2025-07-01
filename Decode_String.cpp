#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;               
        stack<string> resultStack;      
        string current = "";             
        int k = 0;                       

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                resultStack.push(current);
                k = 0;
                current = "";
            } else if (c == ']') {
                string temp = current;
                current = resultStack.top();
                resultStack.pop();

                int repeatTimes = counts.top();
                counts.pop();

                while (repeatTimes--) {
                    current += temp;
                }
            } else {
                current += c;
            }
        }
        return current;
    }
};

int main() {
    Solution solution;
    
    string encoded1 = "3[a2[c]]";
    cout << "Decoded string: " << solution.decodeString(encoded1) << endl;  // Output: accaccacc

    string encoded2 = "2[abc]3[cd]ef";
    cout << "Decoded string: " << solution.decodeString(encoded2) << endl;  // Output: abcabccdcdcdef

    return 0;
}