class Solution {
    int m , n;
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c){
        
        vis[r][c] = 1;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 0) {
                dfs(grid, vis, nr, nc);
            }
        }

    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int islands = 0;

        for(int j = 0; j < n; j++){
            if(grid[0][j] == 0 && vis[0][j] == 0){
                dfs(grid, vis, 0, j);
            }
        }

        for(int j = 0; j < n; j++){
            if(grid[m-1][j] == 0 && vis[m-1][j] == 0){
                dfs(grid, vis, m-1, j);
            }
        }

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0 && vis[i][0] == 0){
                dfs(grid, vis, i, 0);
            }
        }
    
        for(int i = 0; i < m; i++){
            if(grid[i][n-1] == 0 && vis[i][n-1] == 0){
                dfs(grid, vis, i, n-1);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 0){
                    dfs(grid, vis, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};