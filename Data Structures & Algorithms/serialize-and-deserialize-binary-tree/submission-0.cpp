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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans;
        queue<TreeNode*>q{{root}};
        

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node)
            {
                ans+=to_string(node->val)+" ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                ans+="# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
        {
            return nullptr;
                    }
                    stringstream ss(data);
                    string t ;
                    ss>>t;
                    TreeNode* root = new TreeNode(stoi(t));
                    queue<TreeNode*>q{{root}};
                    while(!q.empty())
                    {
                                auto node = q.front();
                                q.pop();
                                ss >> t;
                                if(t!="#")
                                {
                                    node->left  = new TreeNode(stoi(t));
                                    q.push(node->left);
                                }
                                ss >> t;
                                if(t!="#")
                                {
                                    node->right  = new TreeNode(stoi(t));
                                    q.push(node->right);
                                }

                    }
                    return root;
    }
};
