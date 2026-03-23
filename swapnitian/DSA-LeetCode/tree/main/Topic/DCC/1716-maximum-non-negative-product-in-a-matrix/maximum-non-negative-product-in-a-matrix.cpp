class Solution {
private:
    pair<long long , long long> recursion(vector<vector<int>>& grid , int i, int j, int m , int n ,
            vector<vector<pair<long long ,long long>>>&dp){
        // we are having two choices: one is down and second is right
        // in this we are having negative numbers in which we are having the possibility
        // of getting maxprod by using negative no.  
        if(i == m-1 && j == n-1) return {grid[i][j] , grid[i][j] };

        if(dp[i][j] != make_pair(LLONG_MIN , LLONG_MAX)) return dp[i][j] ;

        // each direction will give the two value that is min and max product ;

        long long mini = LLONG_MAX ;
        long long maxi = LLONG_MIN ;

        // first for down 
        

        if(i < m-1){
            auto [downmax , downmin] = recursion(grid , i+1 , j , m , n, dp) ;

            maxi = max({maxi , 1LL*grid[i][j]*downmax , 1LL*grid[i][j]*downmin}) ;
            mini = min({mini , 1LL*grid[i][j]*downmax , 1LL*grid[i][j]*downmin}) ;
        }

        // now for right

        if(j < n-1){
            auto [rightmax , rightmin] = recursion(grid , i ,j+1 , m , n , dp) ;

            maxi = max({maxi , 1LL*grid[i][j]*rightmax , 1LL*grid[i][j]*rightmin}) ;
            mini = min({mini , 1LL*grid[i][j]*rightmax , 1LL*grid[i][j]*rightmin}) ;
        }

        return dp[i][j] = {maxi , mini} ;
    }
public:
    int mod = 1e9 + 7 ;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<pair<long long , long long>>> dp(m+1 , vector<pair<long long ,long long>>(n+1 , {LLONG_MIN , LLONG_MAX})) ;

        auto [maxprod , minprod] = recursion(grid , 0 , 0 , m , n ,dp) ;

        return maxprod < 0 ? -1 : maxprod%mod;
    }
};