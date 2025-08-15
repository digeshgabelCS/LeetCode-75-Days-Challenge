#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Sort products lexicographically
        sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        string prefix = "";
        auto it = products.begin();
        
        // Step 2: Iterate through each character in searchWord
        for (char c : searchWord) {
            prefix += c;
            
            // Step 3: Find the first product >= prefix
            it = lower_bound(it, products.end(), prefix);
            
            // Step 4: Collect up to 3 matching products
            vector<string> suggestions;
            for (auto iter = it; iter != products.end() && suggestions.size() < 3; ++iter) {
                if (iter->compare(0, prefix.size(), prefix) == 0) {
                    suggestions.push_back(*iter);
                } else {
                    break; // Prefix no longer matches
                }
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    
    vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);
    
    // Printing the results
    for (auto &list : ans) {
        for (auto &word : list) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}