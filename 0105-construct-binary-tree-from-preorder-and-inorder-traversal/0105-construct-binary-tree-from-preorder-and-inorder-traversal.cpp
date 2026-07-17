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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder, inorder, mp,
                                0, inorder.size() - 1,
                                0, preorder.size() - 1);
        return root;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     map<int, int>& mp,
                     int inStart, int inEnd,
                     int preStart, int preEnd) {
        if (inStart > inEnd || preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        root->left = helper(preorder, inorder, mp,
                            inStart, inRoot - 1,
                            preStart + 1, preStart + numsLeft);
        root->right = helper(preorder, inorder, mp,
                             inRoot + 1, inEnd,
                             preStart + numsLeft + 1, preEnd);
        return root;
    }
};