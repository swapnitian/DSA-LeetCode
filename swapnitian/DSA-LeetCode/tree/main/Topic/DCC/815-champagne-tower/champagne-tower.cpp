class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // this is good as for simulation + math + dp 
        double dp[101][101] = {0} ;
        dp[0][0] = poured ;

        for(int i = 0 ; i <= query_row ; i++){   
            for(int j = 0 ; j <= i ; j++){
                if(dp[i][j] >= 1){
                    dp[i+1][j] += (dp[i][j]-1)/2.0 ; 
                    dp[i+1][j+1] += (dp[i][j]-1)/2.0 ; // basically this is adding the champagne after pouring into top of the glass 
                    dp[i][j] = 1 ; 
                }
            }
        }
        return dp[query_row][query_glass] ;
    }
};