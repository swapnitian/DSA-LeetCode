class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int endc = y+k ;

        for(int i = y ; i < endc ; i++){
            int st = x ;
            int end = x+k-1 ;

            while(st < end){
                swap(grid[st][i] , grid[end][i]) ;
                st++ ; end-- ;
            }
        }

        return grid ;
    }
};