class Solution {
private:
    TreeNode* search(TreeNode* root, int val){
        if(!root) return nullptr;
        if(root->val == val){
            return root;
        }
        else if(root->val > val){
            return search(root->left, val);
        }
        else{
            return search(root->right, val);
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};