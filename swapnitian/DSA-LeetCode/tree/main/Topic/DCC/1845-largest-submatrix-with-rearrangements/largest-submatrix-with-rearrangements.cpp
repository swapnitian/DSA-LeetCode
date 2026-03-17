class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        int ans = INT_MIN ;
        vector<int> prev_row(n , 0) ;

        for(int i = 0 ; i < m ; i++){
            vector<int> curr_row = matrix[i] ; 
            for(int j = 0 ; j < n ; j++){
                if(curr_row[j] != 0){
                    curr_row[j] += prev_row[j] ;
                }
            }

            // here we will do soting work as 

            vector<int> sorted = curr_row ;
            sort(sorted.rbegin() , sorted.rend()) ;

            for(int j = 0 ; j < n ; j++){
                ans = max(ans , sorted[j] * (j+1)) ; // this is the base expanding 
            }
            prev_row = curr_row ;
        }
        return ans ;
    }
};