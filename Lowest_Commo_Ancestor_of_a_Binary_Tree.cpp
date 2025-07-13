#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }
};

TreeNode* insertLevelOrder(int arr[], int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) { 
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    int arr[] = {3,5,1,6,2,0,8,-1,-1,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = insertLevelOrder(arr, 0, n);

    Solution solution;

    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}