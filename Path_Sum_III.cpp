#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        currentSum += node->val;
        int paths = 0;

        if (prefixSumCount.count(currentSum - targetSum)) {
            paths += prefixSumCount[currentSum - targetSum];
        }

        prefixSumCount[currentSum]++;

        paths += dfs(node->left, currentSum, targetSum, prefixSumCount);
        paths += dfs(node->right, currentSum, targetSum, prefixSumCount);

        prefixSumCount[currentSum]--;

        return paths;
    }
};

TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    int targetSum = 8;

    Solution sol;
    int result = sol.pathSum(root, targetSum);

    cout << "Number of paths with sum " << targetSum << " is: " << result << endl;

    return 0;
}