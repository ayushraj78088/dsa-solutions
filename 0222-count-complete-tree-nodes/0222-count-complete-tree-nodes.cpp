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
    int leftHeight(TreeNode* node) {
        if (!node) return 0;

        int hgt = 0;
        while (node) {
            hgt++;
            node = node->left;
        }

        return hgt;
    }

    int rightHeight(TreeNode* node) {
        if (!node) return 0;

        int hgt = 0;
        while (node) {
            hgt++;
            node = node->right;
        }

        return hgt;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (rh == lh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};