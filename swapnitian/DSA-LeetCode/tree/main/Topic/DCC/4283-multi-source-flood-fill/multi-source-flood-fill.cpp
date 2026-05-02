class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        //  will use MultiBFS--

        vector<vector<int>> grid(n , vector<int>(m , 0)) ;
        vector<vector<int>> dist(n , vector<int>(m , INT_MAX)) ;

        queue<pair<int,int>> q;

        for(auto it : sources){
            grid[it[0]][it[1]] = it[2];
            dist[it[0]][it[1]] = 0;

            q.push({it[0] , it[1]});
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr < 0 || nc < 0 || nc >= m || nr >= n) continue;

                if(dist[nr][nc] > dist[r][c]+1){
                    grid[nr][nc] = grid[r][c];
                    dist[nr][nc] = dist[r][c]+1;

                    q.push({nr , nc});
                }else if(dist[nr][nc] == dist[r][c] +1 ){
                    grid[nr][nc] = max(grid[r][c] , grid[nr][nc]);

                    // q.push({nr , nc});
                }

            }

        }

        return grid;
    }
};