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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        set<int> to_delete_set;
        vector<int>::iterator itr;
        for(itr=to_delete.begin(); itr!=to_delete.end(); itr++) {
            to_delete_set.insert(*itr);
        }
        preOrder(root, result, to_delete_set, true);
        return result;
    }
    TreeNode* preOrder(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) {
            return NULL;
        }
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) {
            result.push_back(node);
        }
        node->left = preOrder(node->left, result, to_delete_set, deleted); // using the fact that when a node is deleted, it's left and right children forms two different trees in the forest
        node->right = preOrder(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }
};
