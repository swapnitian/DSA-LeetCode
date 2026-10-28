class Solution {
    int m, n;
    vector<int> ans;
    void recursion(vector<vector<int>> &grid, int r, int c,
            vector<vector<vector<int>>>& dp, int XOR){
        
        XOR ^= grid[r][c];

        if(dp[r][c][XOR] != -1) return;

        dp[r][c][XOR] = XOR;
        
        if(r == m-1 && c == n-1){
            ans.push_back(XOR);
            return;
        }

        if(r < m-1){
            recursion(grid, r+1, c, dp, XOR);
        }
        if(c < n-1){
            recursion(grid, r, c+1, dp, XOR);
        }

    }
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(1024, -1)));

        recursion(grid, 0, 0, dp, 0);
        int mini = 1024;
        for(int x = 0; x < ans.size(); x++){
            mini = min(ans[x], mini);
        }

        return mini;
    }
};