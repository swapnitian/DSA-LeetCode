class Solution {
private:
    bool special(vector<vector<int>> &mat , int r , int c){
        int m = mat.size() ;
        int n = mat[0].size() ;
        // checking row first ;
        for(int j = 0 ; j < n ; j++){
            if(j == c) continue ;
            if(mat[r][j] == 1){
                return false ;
            }
        }
        // checking column now 
        for(int i = 0 ; i < m ; i++){
            if(i == r) continue ;
            if(mat[i][c] == 1){
                return false ;
            }
        }
        return true ;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        int ans = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    if(special(mat , i , j)){
                        ans++ ;
                    }
                }
            }
        }
        return ans ;
    }
};