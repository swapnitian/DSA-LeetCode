class Solution {
private:
    int solve(vector<vector<int>> &grid, int k , int r , int c , int m , int n){
        vector<int> v ;
        for(int i = r ; i < r+k && i < m ; i++){
            for(int j = c ; j < c+k && j < n ; j++){
                v.push_back(grid[i][j]) ;
            }
        }
        sort(v.begin() , v.end()) ;
        int mini = INT_MAX ;

        for(int i = 0 ; i < (int)v.size()-1 ; i++){
            if(v[i] == v[i+1]) continue ; 
            mini = min(mini , abs(v[i]-v[i+1])) ;
            cout << v[i] << " " ;
        }
        cout << v.back() << endl; 
        return mini == INT_MAX ? 0 : mini ;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>> ans(m-k+1 , vector<int>(n-k+1 , 0)) ;

        for(int i = 0 ;  i < m-k+1 ; i++){
            for(int j = 0 ; j < n-k+1 ; j++){
                ans[i][j] = solve(grid , k , i , j , m , n) ;
            }
        }
        return ans ;
    }
};