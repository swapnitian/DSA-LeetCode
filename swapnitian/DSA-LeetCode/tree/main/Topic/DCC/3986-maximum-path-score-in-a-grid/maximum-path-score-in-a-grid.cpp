class Solution {
private:
    int recursion(vector<vector<int>>& grid , int i , int j , int cost , int k,
                    int m , int n ,vector<vector<vector<int>>>& dp){

        int newcost = cost + ((grid[i][j] != 0) ? 1 : 0) ; 

        if(newcost > k) return INT_MIN ;

        if(dp[i][j][newcost] != -1) return dp[i][j][newcost] ;

        
        if(i == n-1 && j == m-1){
            return grid[i][j] ;
        }
        
        // we are having an option for 0 and 1 ,2 ;

        int down = INT_MIN ;
        int right = INT_MIN ;

        if(i + 1 < n){
            down = grid[i][j] + recursion(grid,i+1,j,newcost,k,m,n,dp) ;
        }
        if(j+1 < m){
            right = grid[i][j] + recursion(grid,i,j+1,newcost,k,m,n,dp) ;
        }

        return dp[i][j][newcost] = max(right , down) ;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid[0].size();
        int n = grid.size() ;

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(k+1,-1))) ;

        int ans = recursion(grid,0,0,0,k,m,n,dp) ;

        return ans < 0 ? -1 : ans ;
    }
};