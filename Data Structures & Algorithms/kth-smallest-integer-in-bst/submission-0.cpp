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
    priority_queue<int,vector<int>,greater<>> h;
public:
    void r(TreeNode* root){
        if(!root) return;
        h.push(root->val);
        r(root->left);
        r(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int c=0;
        r(root);
        while(c!=k-1){
            h.pop();
            c++;
        }
        return h.top();
    }
};
