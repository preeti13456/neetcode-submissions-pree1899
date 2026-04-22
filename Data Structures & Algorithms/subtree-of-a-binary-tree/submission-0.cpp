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
string serialize(TreeNode* root)
{
    if(!root) return "#";
    return ","+to_string(root->val)+serialize(root->left)+serialize(root->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = serialize(root);
        string s2 = serialize(subRoot);
        return s1.find(s2)!=string::npos;
    }
};
