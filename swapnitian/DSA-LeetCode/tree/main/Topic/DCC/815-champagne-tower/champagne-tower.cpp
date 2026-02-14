class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // this is good as for simulation + math + dp 
        double arr[101][101] = {0} ;
        arr[0][0] = poured ;
        for(int i = 0 ; i <= query_row ; i++){   
            for(int j = 0 ; j <= i ; j++){
                if(arr[i][j] >= 1){
                    arr[i+1][j] += (arr[i][j]-1)/2.0 ; 
                    arr[i+1][j+1] += (arr[i][j]-1)/2.0 ; // basically this is adding the champagne after pouring into top of the glass 
                    arr[i][j] = 1 ; 
                }
            }
        }
        return arr[query_row][query_glass] ;
    }
};