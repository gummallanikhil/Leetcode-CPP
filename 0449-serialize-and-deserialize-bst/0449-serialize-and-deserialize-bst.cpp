/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }
    TreeNode* build(vector<int>& pre, int& i, int bound) {
        if (i == pre.size() || pre[i] > bound)
            return nullptr;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = build(pre, i, root->val);
        root->right = build(pre, i, bound);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<int> pre;
        stringstream ss(data);
        int x;
        while (ss >> x)
            pre.push_back(x);
        int i = 0;
        return build(pre, i, INT_MAX);
    }
};