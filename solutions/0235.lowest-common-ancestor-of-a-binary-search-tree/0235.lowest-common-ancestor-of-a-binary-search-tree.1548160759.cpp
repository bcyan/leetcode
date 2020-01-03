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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv = root->val;
        int pv = p->val;
        int qv = q->val;
        if (rv == pv || rv == qv) {
            return root;
        } else if (pv < rv && qv < rv) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (pv > rv && qv > rv) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
    
};
