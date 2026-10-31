class Solution {
    int m, n;
    int mod = 1e9 + 7;
    int dp[501][501][2];
    int CountPaths(vector<vector<int>> &grid, int r, int c, int dir){
        if(r == m-1 && c == n-1){
            return 1;
        }

        if(dp[r][c][dir] != -1) return dp[r][c][dir];
 
        int cnt = 0;
        if(grid[r][c] == 1){
            if(dir == 0){ // means this has come by right direction
                if(r < m-1){
                    cnt += CountPaths(grid, r+1, c, 1);
                }
            }else{
                if(c < n-1){
                    cnt += CountPaths(grid, r, c+1, 0);
                }
            } 
        }else{
            if(r < m-1){
                cnt += CountPaths(grid, r+1, c, 1);
            }
            if(c < n-1){
                cnt += CountPaths(grid, r, c+1, 0);
            }    
        }
        return dp[r][c][dir] = cnt%mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
    
        // CountPaths(grid, 0, 0, 0);

        memset(dp, -1, sizeof(dp));

        return CountPaths(grid, 0, 0, 0)%mod;
    }
};