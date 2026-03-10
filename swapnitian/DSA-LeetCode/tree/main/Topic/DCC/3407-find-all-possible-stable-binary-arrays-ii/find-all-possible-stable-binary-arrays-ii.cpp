class Solution {
private :
    int recursion(int zeroleft , int oneleft , int limit , int prev ,
                    vector<vector<vector<int>>>&dp){

        if(zeroleft == 0 && oneleft == 0){
            return 1 ;
        }   

        if(dp[zeroleft][oneleft][prev] != -1) return dp[zeroleft][oneleft][prev] ;

        int ans = 0 ;

        if(prev == 0){ // explore all 1's here 
            for(int len = 1 ; len <= min(oneleft , limit) ; len++){
                ans = (ans + recursion(zeroleft , oneleft-len , limit , 1 ,dp))%mod ;
            }
        }else { // explore all 0's here 
            for(int len = 1 ; len <= min(zeroleft , limit) ; len++){
                ans = (ans + recursion(zeroleft-len , oneleft , limit , 0 ,dp))%mod ;
            }
        }
        return dp[zeroleft][oneleft][prev] =  ans ;
    }
public:
    long long mod = 1e9 + 7 ;
    int numberOfStableArrays(int zero, int one, int limit) {

    //     vector<vector<vector<int>>> dp(zero+1 , vector<vector<int>>(one+1 , vector<int>(2,-1)));

    //     int st0 = recursion(zero , one , limit , 1 ,dp) ; // start with 0 ;
    //     int st1 = recursion(zero , one , limit , 0 ,dp) ; // start with 1 ;

    //     return (st0+st1)%mod ;
        
    
        vector<vector<vector<int>>>dp(zero+1 , vector<vector<int>>(one+1 , vector<int>(2,0))) ;
        // initiliaze the base case ;
        
        for(int i = 0 ; i <= min(zero , limit) ; i++){ // this is when we use 1-> 0 times
            dp[i][0][1] = 1 ; // if we use 1 -> 0 times so it will end with 0 
        }

        for(int j = 0 ; j <= min(one , limit) ; j++){ // this is when we use 0 -> 0 times
            dp[0][j][0] = 1 ; // if we use 0 -> 0 times then it will end with 1 
        }

        // here i -> zeroleft , j -> oneleft 
        for(int i = 0 ; i <= zero ; i++){
            for(int j = 0 ; j <= one ; j++){
                if(i == 0 || j == 0) continue ;
                
                // when we explore all 0's
                // we will use the formula that we derived  
                dp[i][j][1] = (dp[i-1][j][1] + dp[i-1][j][0])%mod ;

                if(i-1 >= limit){
                    dp[i][j][1] = ( dp[i][j][1] - dp[i-1-limit][j][0] + mod) % mod ;
                }

                // similarly when we explore all 1's 
                // we will use the formula that we derived 
                dp[i][j][0] = (dp[i][j-1][0] + dp[i][j-1][1])%mod ; 

                if(j-1 >= limit){
                    dp[i][j][0] = ( dp[i][j][0] - dp[i][j-1-limit][1] + mod ) % mod ;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1])%mod ;
    }   
};