class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size() ;
        vector<vector<int>>copy = mat ;
        for(int rot = 0 ; rot < 4 ; rot++){
            for(int i = 0 ; i < n ; i++){
                vector<int> help ;
                for(int j = 0 ; j < n ; j++){
                    help.push_back(mat[i][j]) ;
                }
                // here we will perform the rotate part 
                int idx = 0 ;
                for(int row = 0 ; row < n ; row++){
                    copy[row][n-i-1] = help[idx] ;
                    idx++ ; 
                }
            }
            mat = copy ; 
            if(mat == target) return true ;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << copy[i][j] << " " ;
            }
            cout << endl;
        }
        return false ;
    }
};