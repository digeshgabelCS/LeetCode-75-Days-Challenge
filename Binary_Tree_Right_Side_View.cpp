#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return result;
    }
};

TreeNode* createSampleTree() {
    // Constructing the following tree:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, nullptr, node5);
    TreeNode* node3 = new TreeNode(3, nullptr, node4);
    TreeNode* root = new TreeNode(1, node2, node3);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    vector<int> rightView = sol.rightSideView(root);
    
    cout << "Right side view of the tree: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}