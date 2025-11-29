/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Function to calculate maximum depth of the tree
    int maxDepth(TreeNode* root) {

        // 🔹 If the root is NULL, there is no tree → depth = 0
        if(root == nullptr) {
            return 0;
        }

        // 🔹 Recursively find depth of left subtree
        int leftDepth = maxDepth(root->left);

        // 🔹 Recursively find depth of right subtree
        int rightDepth = maxDepth(root->right);

        // 🔹 Maximum depth = larger one + 1 (count current node)
        return 1 + max(leftDepth, rightDepth);
    }
};
