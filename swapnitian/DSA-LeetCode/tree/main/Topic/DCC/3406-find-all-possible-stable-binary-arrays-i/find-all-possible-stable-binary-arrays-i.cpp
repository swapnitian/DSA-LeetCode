class Solution {
    int recursion(int zeroleft , int oneleft , int limit , int prev,
                    vector<vector<vector<int>>>&dp){
        // if( prev == 1) means we use previous 1 else 0 ;

        if(zeroleft == 0 && oneleft == 0) return 1; 

        if (dp[oneleft][zeroleft][prev] != -1 ) return dp[oneleft][zeroleft][prev] ;

        int ans = 0 ; // this will hold all possible stavle arrays 

        if(prev == 1){ // exploring all 0's
            // here we attached zeroes to the current array ;

            for(int len = 1 ; len <= min(zeroleft , limit) ; len++) {
                ans =  (ans + recursion(zeroleft-len , oneleft , limit , 0 , dp)) % mod ;
            }

        }else{ // exploring all 1's 

            for(int len = 1 ; len <= min(oneleft , limit) ; len++) {
                ans = (ans + recursion(zeroleft , oneleft-len , limit , 1 , dp)) % mod ;
            }
        }
        return dp[oneleft][zeroleft][prev] = ans;
    }   
public:
    long long mod = 1e9 + 7 ;
    int numberOfStableArrays(int zero, int one, int limit) {
        // solved by reccursion --- 
        // if i want to start with 1 means we use 0 to start ; 
        // if i want to start with 0 means we will use 1 to start ;
        
        vector<vector<vector<int>>>dp(one+1 , vector<vector<int>>(zero+1 , vector<int>(2 , -1))) ;

        int st0 = recursion(zero , one , limit ,1 ,dp) ;
        int st1 = recursion(zero , one , limit , 0 ,dp) ;
        
        return  (st0 + st1)%mod ;
    }
};