class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int mintime = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            mintime = t;

            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                if(grid[nr][nc] == 0 || grid[nr][nc] == 2) continue;
                
                if(vis[nr][nc] == 1) continue;

                vis[nr][nc] = 1;
                grid[nr][nc] = 2;
                q.push({{nr, nc}, t+1});
            }   
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return mintime;
    }
};