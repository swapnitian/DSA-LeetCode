class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size() ; long long m = grid[0].size() ;

        vector<vector<long long>>prefix(n+1 , vector<long long>(m+1,0)) ;

        for(long long i = 1 ; i <= n; i++){
            for(long long j =1 ; j <= m ; j++){
                prefix[i][j] = grid[i-1][j-1] + prefix[i][j-1] +prefix[i-1][j] - prefix[i-1][j-1] ;
            }
        }
        // for horizontal cuts --> 
        long long sum1 = 0 ; long long sum2 = 0 ;
        for(int i = 1 ; i < n ; i++){
            sum1 = prefix[i][m] ;
            sum2 = prefix[n][m] - sum1 ;

            if(sum1 == sum2) return true ;
        }
        // for vertical cuts -->
        for(int i = 1 ; i < m ; i++){
            sum1 = prefix[n][i] ;
            sum2 = prefix[n][m] - sum1 ;

            if(sum1 == sum2) return true ;
        }

        return false ;
    }
};