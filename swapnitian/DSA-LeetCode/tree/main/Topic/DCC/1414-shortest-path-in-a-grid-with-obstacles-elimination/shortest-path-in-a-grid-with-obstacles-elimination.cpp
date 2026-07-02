class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
    
        vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(m+1, vector<int>(k+1,0)));
        vis[0][0][k] = 1;

        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{0, 0},{k, 0}});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int K   = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            if(row == n-1 && col == m-1) return dist;

            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
            
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[nrow][ncol] == 1){
                        if(K > 0 && (vis[nrow][ncol][K-1] == 0)){
                            vis[nrow][ncol][K-1] = 1;
                            q.push({{nrow,ncol}, {K-1, dist+1}});
                        }
                    }else{
                        if(vis[nrow][ncol][K] == 0){
                            vis[nrow][ncol][K] = 1;
                            q.push({{nrow,ncol}, {K, dist+1}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};