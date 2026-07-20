class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push({dist[0][0], 0, 0});
        vis[0][0] = 1;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int safe = cur[0];
            int x = cur[1];
            int y = cur[2];
            if(x == n - 1 && y == n - 1)
                return safe;
            for(auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({min(safe, dist[nx][ny]), nx, ny});
                }
            }
        }
        return 0;
    }
};