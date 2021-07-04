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
bool comparator(TreeNode* a, TreeNode* b) {
    return a->val < b->val;
}
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodesRecursive(root, NULL);
    }
    int goodNodesRecursive(TreeNode* root, TreeNode* highest) {
        if (!root) return 0;
        TreeNode* newHighest = highest != NULL ? max(highest, root, comparator) : root;
        int count = goodNodesRecursive(root->left, newHighest) + goodNodesRecursive(root->right, newHighest);
        if (highest != NULL && root->val < highest->val) return count;
        return 1 + count;
    }
};
