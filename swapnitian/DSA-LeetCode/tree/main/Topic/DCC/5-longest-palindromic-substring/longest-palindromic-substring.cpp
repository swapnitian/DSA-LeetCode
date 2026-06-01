class Solution {
public:
    string longestPalindrome(string s) {
        // bottom up approach DP
        int n = s.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(n+1 , false));
        int st = 0; int length = 1;
        for(int len = 1; len <= n; len++){
            for(int i = 0; i+len-1 < n; i++){
                int j = i+len-1;
    
                if(i == j){
                    dp[i][j] = true;
                }else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]){
                    st = i;
                    length = max(length , j-i+1);
                }
            }
        }
        return s.substr(st, length);
    }
};