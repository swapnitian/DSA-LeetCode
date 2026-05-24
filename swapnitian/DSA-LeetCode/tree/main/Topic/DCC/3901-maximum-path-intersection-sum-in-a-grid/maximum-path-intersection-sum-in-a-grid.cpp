class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1e9;

        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                ans = max(ans , grid[i][j]);
            }
        }

        for(int i = 0; i < m; i++){
            int sum = grid[i][0]; int maxi = -1e9;
            for(int j = 1; j < n; j++){
                sum += grid[i][j];

                maxi = max(maxi , sum);

                sum = max(sum , grid[i][j]);
            }
            ans = max(ans , maxi);
        }

        for(int j = 0; j < n; j++){
            int sum = grid[0][j];
            int maxi = -1e9;
            for(int i = 1; i < m; i++){
                sum += grid[i][j];

                maxi = max(maxi , sum);

                sum = max(sum , grid[i][j]);
            }
            ans = max(ans , maxi);
        }

        return ans;
    }
};