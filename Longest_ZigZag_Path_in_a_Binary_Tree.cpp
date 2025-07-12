#include <iostream>
#include <algorithm>
using namespace std;

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
    int maxLength = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;

        maxLength = max(maxLength, length);
        
        if (isLeft) {
            dfs(node->right, false, length + 1);
            dfs(node->left, true, 1);
        } else {
            dfs(node->left, true, length + 1);
            dfs(node->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, true, 1);  
        dfs(root->right, false, 1); 
        return maxLength;
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
             \    \
              4    5
             / \    \
            6   7    8
    */

    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->right->right = newNode(5);
    root->right->right->right = newNode(8);

    Solution sol;
    int result = sol.longestZigZag(root);

    cout << "Longest ZigZag Path Length: " << result << endl;

    return 0;
}