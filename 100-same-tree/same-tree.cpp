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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1️⃣ If both nodes are NULL, trees are same up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // 2️⃣ If one is NULL and other is not, structure is different
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // 3️⃣ If values of current nodes are different, trees are not same
        if (p->val != q->val) {
            return false;
        }

        // 4️⃣ Recursively check left subtree and right subtree
        bool leftSame  = isSameTree(p->left,  q->left);
        bool rightSame = isSameTree(p->right, q->right);

        // 5️⃣ Trees are same only if both left and right subtrees are same
        return leftSame && rightSame;
    }
};
