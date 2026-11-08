class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // we have to check for each element by col
                if(grid[i][j] == 0) continue;
                bool f1 = false;
                for(int row = 0; row < m; row++){
                    if(row == i) continue;
                    if(grid[row][j] == 1){
                        cnt++;
                        f1 = true;
                        break;
                    }
                }
                if(f1) continue;
            
                // by row;
                for(int col = 0; col < n; col++){
                    if(col == j) continue;
                    if(grid[i][col] == 1){
                        cnt++;
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};