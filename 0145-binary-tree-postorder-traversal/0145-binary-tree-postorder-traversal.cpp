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

    void ans(TreeNode* root, vector<int> &pre){
        if(!root){
            return;
        }
        ans(root->left, pre);
        ans(root->right, pre);
        pre.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre;
        ans(root, pre);
        return pre;
    }
};