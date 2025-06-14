#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // index where we write next compressed char/number
        int read = 0;  // index to read through the input

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count occurrences of the current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // If count > 1, write the count as characters
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        // The array is modified in-place up to 'write'
        return write;
    }
};

int main() {
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};

    // Compress the array
    int newLength = sol.compress(chars);

    // Output the compressed array and its new length
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}