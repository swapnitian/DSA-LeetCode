class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
    
        while(k--){
            vector<vector<int>> copy = grid;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(j < n-1){
                        grid[i][j+1] = copy[i][j];
                    }else if(i != m-1 && j == n-1){
                        grid[i+1][0] = copy[i][j];
                    }else if(i == m-1 && j == n-1){
                        grid[0][0] = copy[i][j];
                    }
                }
            }
        }
        return grid;
    }
};