class Solution {
private:
    int recursion(vector<vector<int>>& coins , int i , int j , int m , int n , int limit,
                    vector<vector<vector<long long>>>& dp){

        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && limit > 0) return 0 ;
            else return coins[i][j] ;
        }
        // now we have two options that the coins will be +ve or -ve 
        // also we are having negative no. so for that we have to take care

        if(dp[i][j][limit] != LLONG_MIN) return dp[i][j][limit] ;

        long long right = LLONG_MIN ;
        long long down = LLONG_MIN ;
        
        // in this we have more two choices that i can skip neutralize or not 

        // choice 1 skip the neutralization 

        if(i < m-1){
            down = coins[i][j] + recursion(coins , i+1 , j , m , n , limit ,dp) ;
        }
        if(j < n-1){
            right = coins[i][j] + recursion(coins , i , j+1 , m , n , limit ,dp) ;
        }

        // choice 2 use the neutralization

        if(limit > 0 && coins[i][j] < 0){
            if(i < m-1){
                down = max(down*1LL ,  1LL*recursion(coins , i+1 , j , m , n , limit-1 ,dp)) ;
            }
            if(j < n-1){
                right = max(right , 1LL*recursion(coins , i , j+1 , m , n , limit-1 ,dp)) ;
            }
        }
        return dp[i][j][limit] = max(right , down) ;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size() ;
        int n = coins[0].size() ;
        // vector<vector<vector<long long>>>dp(m+1 , vector<vector<long long>>(n+1 , vector<long long>(3 , LLONG_MIN))) ;
        // return recursion(coins , 0 , 0 , m , n , 2 ,dp) ;


        // will try tabulation method -- 

        vector<vector<vector<long long>>>dp(m , vector<vector<long long>>(n , vector<long long>(3 , LLONG_MIN))) ;

        // defining base case -->

        for(int lt = 0 ; lt <= 2 ; lt++){
            if(lt > 0 && coins[m-1][n-1] < 0){
                dp[m-1][n-1][lt] = 0LL ;
            }else{
                dp[m-1][n-1][lt] = coins[m-1][n-1] ;
            }
        }

        // whole recursion logic ;

        for(int i = m-1 ; i >= 0; i--){
            for(int j = n-1 ; j >= 0; j--){
                if(i == m-1 && j == n-1) continue ;

                for(int lt = 0; lt <= 2 ; lt++){

                    long long down = LLONG_MIN ;
                    long long right = LLONG_MIN ;

                    // choice 1 skip the neutralization---
                    if(i < m-1){
                        down = coins[i][j] + dp[i+1][j][lt] ;
                    }
                    if(j < n-1){
                        right = coins[i][j] + dp[i][j+1][lt] ;
                    }

                    // choice 2 use the neutralization 

                    if(lt > 0 && coins[i][j] < 0){
                       if(i < m-1){
                            down = max(down , dp[i+1][j][lt-1]) ;
                        }
                        if(j < n-1){
                            right = max(right , dp[i][j+1][lt-1]) ;
                        } 
                    }
                    dp[i][j][lt] = max(right , down) ;
                }
            }
        }
        return dp[0][0][2] ;
    }
};