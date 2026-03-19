class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ; 

        vector<vector<int>>pref(m+1 , vector<int>(n+1 , 0)) ;
        vector<int> cntX(n+1 , 0) ;
        int ans = 0 ;
        for(int i = 1 ; i <= m ; i++){
            int cntx = 0 ;
            for(int j = 1 ; j <= n ; j++){
                if(grid[i-1][j-1] == 'X'){
                    pref[i][j] = 1 + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] ;
                    cntx++ ;
                }else if(grid[i-1][j-1] == 'Y'){
                    pref[i][j] = -1 + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] ;
                }else {
                    pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] ;
                }
                cntX[j] += cntx ;
                if(pref[i][j] == 0 && cntX[j] > 0) ans++ ;
            }
        }
        return ans ;
    }
};