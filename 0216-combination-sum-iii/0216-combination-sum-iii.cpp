class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(int k, int n, int start) {
        if (k == 0 && n == 0) {
            ans.push_back(path);
            return;
        }
        if (k == 0 || n < 0)
            return;
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return ans;
    }
};