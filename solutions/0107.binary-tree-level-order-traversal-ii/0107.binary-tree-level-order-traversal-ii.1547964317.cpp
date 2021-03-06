/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        traverse(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void traverse(vector<vector<int>>& order, TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (order.size() <= depth) {
            vector<int> level;
            order.push_back(level);
        }
        order[depth].push_back(root->val);
        traverse(order, root->left, depth + 1);
        traverse(order, root->right, depth + 1);
    }
};
