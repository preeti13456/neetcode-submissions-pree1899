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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        //if tree empty return res
        if(!root) return res;
        //BFS Queue and push root 
        queue<TreeNode*>q;
        q.push(root);
        //as long as nodes to process
        while(!q.empty())
        {
            int sz = q.size();
            //process each level node 
            //       1
            //      / \
            //     2    3
            //    / \  / \
            //  NULL 4 null 5
             //q = [2,3]
             //q = [3] //pop 2
             //q=[4,5] //pop 4
             //since 3 is last we reached end of queue sixze
             //since 5 is last we reached end of queue sixze
            for(int i=0; i<sz; i++)
            {
                //grab from queue
                //Level 1 node is 1 -> rightmost = 1
                //
                TreeNode* node = q.front(); q.pop();
                //res = [1, 3, 5]
                //last node at this level push the vlue to result
                if(i==sz-1) res.push_back(node->val);//last node at this level
                //add left and right children
                //q = [2,3]
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

        }
        return res;
    }
};
