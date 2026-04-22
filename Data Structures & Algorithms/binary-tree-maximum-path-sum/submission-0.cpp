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
    private:
    int result = INT_MIN;
    int traverse(TreeNode* root)
    {
        if(!root) return 0;
        int l = max(0, traverse(root->left));
        int r = max(0, traverse(root->right));
        result = max(result, root->val+l+r);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
            traverse(root);
            return result;
    }
};
