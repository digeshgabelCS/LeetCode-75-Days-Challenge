#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
            
            ++currentLevel;
        }
        
        return maxLevel;
    }
};

int main() {
    // Build a simple tree:
    //       1
    //      / \
    //     7   0
    //    / \
    //   7  -8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    
    Solution solution;
    int result = solution.maxLevelSum(root);
    
    cout << "Level with maximum sum: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}