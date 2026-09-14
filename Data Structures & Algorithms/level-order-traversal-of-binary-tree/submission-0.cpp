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
    vector<vector<int>> v;
    void rec(TreeNode* root, int d){
        if(!root) return;
        v[d].push_back(root->val);
        rec(root->left,d+1);
        rec(root->right,d+1);
        return;
    }
    int dep(TreeNode* root,int d){
        if(!root) return 0;
        return 1+max(dep(root->left,d+1),dep(root->right,d+1));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth= dep(root,1);
        printf("%d\n",depth);
        v=vector<vector<int>>(depth);
        rec(root,0);
        return v;
    }
};
