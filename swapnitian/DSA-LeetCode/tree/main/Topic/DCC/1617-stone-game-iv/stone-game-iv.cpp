class Solution {
    int dp[2][100001];
    bool recursion(int person, int n){
        if(n == 0){
            // if(person == 0) return true;

            return false;
        }

        if(dp[person][n] != -1) return dp[person][n];

        bool ans = false;
        for(int x = 1; x*x <= n; x++){
            ans =  ans | (!recursion(!person, n-x*x));
        }
        return dp[person][n] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return recursion(1, n);
    }
};