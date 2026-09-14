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
    vector<int> v;
public:
    void r(TreeNode* root){
        if(!root) return;
        r(root->left);
        v.emplace_back(root->val);
        r(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        r(root);
        return v[k-1];
    }
};
