class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &visited, int n, int m, vector<vector<int>>& grid){
        visited[i][j] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int area = 1;
        for(int k = 0; k<4;k++){
            int newi = i + drow[k];
            int newj = j + dcol[k];
            if(newi >=0 && newi <n && newj >=0 && newj < m && !visited[newi][newj] && grid[newi][newj]==1){
                area += dfs(newi,newj,visited,n,m,grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxArea = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    maxArea = max(maxArea, dfs(i,j,visited,n,m,grid));
                }
            }
        }        
        return maxArea;
    }
};
