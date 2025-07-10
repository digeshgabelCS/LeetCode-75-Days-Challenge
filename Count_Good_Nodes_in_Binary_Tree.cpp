#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    
private:
    int dfs(TreeNode* node, int maxVal) {
        if (node == nullptr) return 0;
        
        int good = 0;
        if (node->val >= maxVal) good = 1;
        
        maxVal = std::max(maxVal, node->val);
        
        good += dfs(node->left, maxVal);
        good += dfs(node->right, maxVal);
        
        return good;
    }
};

int main() {
    // Building a sample tree:
    //        3
    //       / \
    //      1   4
    //         / \
    //        1   5
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    int result = sol.goodNodes(root);
    cout << "Number of good nodes: " << result << endl;

    // Clean up allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}