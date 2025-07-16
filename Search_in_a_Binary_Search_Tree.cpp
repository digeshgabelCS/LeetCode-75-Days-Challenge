#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)
            return root;
        
        if (val < root->val)
            return searchBST(root->left, val);
        
        return searchBST(root->right, val);
    }
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = nullptr;

    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 3);

    int target = 2;

    Solution sol;
    TreeNode* result = sol.searchBST(root, target);

    if (result) {
        cout << "Subtree rooted at " << target << ": ";
        printInOrder(result);
        cout << endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }

    return 0;
}