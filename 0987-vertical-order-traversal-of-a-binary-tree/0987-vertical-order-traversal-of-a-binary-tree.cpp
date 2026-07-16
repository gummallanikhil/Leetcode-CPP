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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; //[]
        map<int, map<int, multiset<int>>> nodes; //[0][0]=3
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); //{7,2,2}
        while(!q.empty()){
        auto curr = q.front(); q.pop();
        TreeNode* node = curr.first; //7
        int x = curr.second.first, y=curr.second.second;
        //x=2, y=2
        nodes[x][y].insert(node->val);
        //[0][0]=3, [-1][1]=9,[1][1]=20,[0][2]=15,[2][2]=7
        if(node->left){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            q.push({node->right,{x+1,y+1}});
        } }
        for(auto i:nodes){
            vector<int> col;//[[9]]
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end()); }
            ans.push_back(col); }
        return ans;
    }
};