#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> result;
        int m = potions.size();

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;

            auto it = std::lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end() - it;
            result.push_back(count);
        }

        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> spells = {10, 20, 30};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 100;

    Solution sol;
    std::vector<int> pairs = sol.successfulPairs(spells, potions, success);

    std::cout << "Successful pairs per spell: ";
    printVector(pairs);

    return 0;
}