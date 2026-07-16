//Push root->left and root->right into a queue.
// While the queue is not empty:
// Pop two nodes.
// If both are nullptr, continue.
// If one is nullptr or their values are different, return false.
// Push their children in mirror order:
// left->left and right->right
// left->right and right->left
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* n1 = q.front(); q.pop();
            TreeNode* n2 = q.front(); q.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2 || n1->val != n2->val)
                return false;
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);
        }
        return true;
    }
};