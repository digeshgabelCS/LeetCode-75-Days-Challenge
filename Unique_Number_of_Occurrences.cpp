#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }
        
        unordered_set<int> occurrences;
        for (auto& pair : countMap) {
            if (occurrences.find(pair.second) != occurrences.end()) {
                return false; 
            }
            occurrences.insert(pair.second);
        }
        
        return true; 
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};

    if (sol.uniqueOccurrences(arr1)) {
        cout << "Test Case 1: True" << endl;
    } else {
        cout << "Test Case 1: False" << endl;
    }

    if (sol.uniqueOccurrences(arr2)) {
        cout << "Test Case 2: True" << endl;
    } else {
        cout << "Test Case 2: False" << endl;
    }

    return 0;
}