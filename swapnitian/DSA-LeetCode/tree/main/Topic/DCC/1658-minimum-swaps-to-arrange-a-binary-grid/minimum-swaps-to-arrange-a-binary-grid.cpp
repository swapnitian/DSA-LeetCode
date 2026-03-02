class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size() ;
        vector<int> pos(n , -1) ;

        // at first we trying to find the mostright1 idx in every row by this we can know the 
        // it is able to swap or not !! 

        for(int i = 0 ; i < n ; i++){
            for(int j = n-1 ; j >=0 ; j--){
                if(grid[i][j] == 1){
                    pos[i] = j ;
                    break ;
                }
            }
        }
        // now the real operations begin to check + to calculate the swap operations in this we try
        // as we required only arrangement it can be done by having the position of the valid rows 
        // so then we simply do the swaps make the grid good ;
        int ans = 0 ; 
        for(int i  = 0 ; i <n ; i++){
            int shift = -1 ;
            for(int j = i ; j < n ; j++){
                // / it is representing as we know for the first row we req. only 1 then so on 
                if(pos[j] <= i){
                    ans += (j-i) ;
                    shift = j ;
                    break; 
                }
            }
            if(shift != -1){
                for(int j = shift ; j>i ; j--){
                    swap(pos[j] , pos[j-1]) ;
                }
            }else return -1 ;
        }
        return ans ;
    }
};