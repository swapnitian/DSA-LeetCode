class Solution {
    bool solve(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        set <long long> s;

        long long total = 0 ;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j] ;
            }
        }

        // here our main logic comes --->
        long long top = 0 ;
        for(int i = 0 ; i < m-1 ; i++){
            for(int j =0 ; j < n; j++){
                s.insert(grid[i][j]) ;
                top += grid[i][j] ; 
            }
            long long bottom = total-top ;
            long long diff = top-bottom ;

            if(diff == 0) return true ;

            if(diff == 1LL*grid[0][0] || diff == 1LL*grid[0][n-1]) return true ;

            if(diff == 1LL*grid[i][0]) return true ;

            if(i > 0 && n > 1 && s.count(diff)) return true ;

        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
      
        if(solve(grid)) return true ;

        reverse(grid.begin() , grid.end()) ;

        if(solve(grid)) return true ;


        // trick to deal with vertical cut that is take the transpose of grid it will rotate by 90
        // then use the same function solve to solve it.......
        reverse(grid.begin() , grid.end()) ;

        vector<vector<int>> transpose(n , vector<int>(m , 0)) ;

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                transpose[j][i] = grid[i][j] ;
            }
        }

        if(solve(transpose)) return true ;

        reverse(transpose.begin() , transpose.end()) ;

        if(solve(transpose)) return true ;

        return false ;
    }
};