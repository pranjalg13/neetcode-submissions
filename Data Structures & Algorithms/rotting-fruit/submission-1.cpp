class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        // 1 0 -1 0
        // 0 1 0 -1
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int t = it.second;
            ans = max(ans, t);
            for (int i = 0; i < 4; i++) {
                int newx = x + drow[i];
                int newy = y + dcol[i];
                if (newx >= 0 && newx < n && newy < m && newy >= 0 && visited[newx][newy] != 2 &&
                    grid[newx][newy] == 1) {
                    q.push({{newx, newy}, t + 1});
                    visited[newx][newy] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
