class Solution {
public:
    int func(vector<vector<int>>& mat, int n, int m, int col) {
        int maxRow = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > mat[maxRow][col]) {
                maxRow = i;
            }
        }
        return maxRow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxRow = func(mat, n, m, mid);
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;
            if (mat[maxRow][mid] > left &&
                mat[maxRow][mid] > right) {
                return {maxRow, mid};
            }
            else if (mat[maxRow][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};