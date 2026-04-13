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
int func(vector<vector<int>>&res, TreeNode* root)
{
if(root==NULL) return -1;
int left_height = func(res, root->left);
int right_height = func(res, root->right);
int curr_height = max(left_height, right_height)+1;

if(res.size()<curr_height+1)
    res.push_back(vector<int>{});

    res[curr_height].push_back(root->val);
    return curr_height;
}
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>res;
        func(res, root);
        return res;
    }
};
