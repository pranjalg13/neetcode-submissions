class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>>& grid, int n, int m){
        visited[i][j] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int newi = i + drow[k];
            int newj = j + dcol[k];
            if(newi >= 0 && newi < n && newj < m && newj >=0 && grid[newi][newj] == '1' && !visited[newi][newj]){
                dfs(newi,newj,visited,grid, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> visited(n , vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,visited, grid, n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
