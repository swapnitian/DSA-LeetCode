class Solution {
private:
    void recursion(vector<vector<int>>& grid , int r , int c , int m , int n 
                         , vector<long long>&ans , long long XOR
                          , vector<vector<vector<long long>>>&dp){
        
        XOR ^= grid[r][c] ;

        if(dp[r][c][XOR] != -1) return ;

        dp[r][c][XOR] = XOR ;
        
        if(r == m-1 && c == n-1){
            ans.push_back(XOR); 
            return ;
        }

        if(r < m-1){
            recursion(grid , r+1 , c , m , n , ans , XOR ,dp) ;
        }
        if(c < n-1){
            recursion(grid , r , c+1 , m , n , ans , XOR ,dp) ;
        } 
        
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<long long>ans ;
        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1 , vector<long long>(1024 , -1))) ;
        recursion(grid , 0 , 0 , m , n , ans , 0LL , dp) ;
    
        long long mini = LLONG_MAX ;

        for(int i = 0 ; i < ans.size() ; i++){
            mini = min(mini , ans[i]) ;
        }

        return mini ;
    
    }
};