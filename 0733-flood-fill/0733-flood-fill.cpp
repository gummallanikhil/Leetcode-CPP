class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int oldColor) {
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                image[nr][nc] == oldColor &&
                image[nr][nc] != color) {
                dfs(image, nr, nc, color, oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color)
            return image;
        dfs(image, sr, sc, color, oldColor);
        return image;
    }
};