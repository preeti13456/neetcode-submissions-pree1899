class Solution {
public:
    int kthSmallestHelper(TreeNode* root, int& k) {
        if (!root) return -1;
        int l = kthSmallestHelper(root->left, k);
        if (l != -1) return l;
        k--;
        if (k == 0) return root->val;
        return kthSmallestHelper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }
};