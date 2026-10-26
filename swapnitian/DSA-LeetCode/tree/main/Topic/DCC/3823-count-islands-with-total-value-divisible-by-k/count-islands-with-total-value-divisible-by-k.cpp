class Solution {
    int m, n;
using ll = long long;
    ll dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c){
        vis[r][c] = 1;
    
        int delrow[4] = {-1, 0, 1, 0}; 
        int delcol[4] = {0, 1, 0, -1}; 

        ll sum = grid[r][c];
        for(int i = 0; i < 4; i++){
            int nr = delrow[i] + r;
            int nc = delcol[i] + c;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] != 0){
                sum += dfs(grid, vis, nr, nc);
            }

        }

        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
    
        vector<vector<int>> vis(m, vector<int>(n ,0));

        int islands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] != 0){
                    ll sum = dfs(grid, vis, i, j);
                    if(sum%k == 0) islands++;
                }
            }
        }

        return islands;
    }
};