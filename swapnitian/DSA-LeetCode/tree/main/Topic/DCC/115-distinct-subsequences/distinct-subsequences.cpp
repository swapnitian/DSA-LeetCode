class Solution {
private:
    int recursion(int i , int j , string &s, string &t , vector<vector<int>> &dp){

        if(j == 0) return 1 ;
        if(i == 0) return 0 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        if(s[i-1] == t[j-1]) return dp[i][j] = recursion(i-1 , j-1 , s , t ,dp) + recursion(i-1 , j , s, t ,dp) ;
        
        return dp[i][j] = recursion(i-1 , j , s , t ,dp) ;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size() ; int m = t.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1)) ;

        // return recursion(n , m , s ,t , dp);


        // T A B U L A T I O N - - 

        vector<vector<long long>> dp2(n+1 , vector<long long>(m+1 , 0)) ;
        int mod = INT_MAX ;
        for(int i = 0 ; i <= n ; i++) dp2[i][0] = 1 ;

        for(int j = 1 ; j <= m ; j++) dp2[0][j] = 0 ;    

        //  S P A C E  O P T I M I Z A T I O N -

        vector<long long>prev(m+1 , 0) ;
        prev[0] = 1 ; 

        for(int i = 1 ; i <= n ; i++){
            for(int j = m ; j >= 1 ; j--){
                if(s[i-1] == t[j-1]) prev[j] = (prev[j-1] + prev[j])%mod ;  
            }
        }
        return prev[m] ;
    }
};