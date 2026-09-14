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

int rec(TreeNode* root, int lastGood){
    if(!root) return 0;

    if(root->val>=lastGood) {printf("%d\n",root->val);return 1 + rec(root->left, root->val) + rec(root->right, root->val);}
    return rec(root->left, lastGood)+rec(root->right, lastGood);;
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return rec(root,root->val);
    }
};
