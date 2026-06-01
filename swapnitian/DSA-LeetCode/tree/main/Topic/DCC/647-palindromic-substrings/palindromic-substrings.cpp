class Solution {
bool dp[1002][1002];
bool check(string &s, int i, int j){
    if(i > j) return true;

    if(dp[i][j] != false) return dp[i][j];

    if(s[i] == s[j]){
        if(check(s, i+1, j-1)) return dp[i][j] = true;
    }
    return dp[i][j] = false;
}
public:
    int countSubstrings(string s) {
        int n = s.size();
        // int cnt = 0;
        // int ans = 1;
        // memset(dp, false, sizeof(dp));
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         if(check(s, i, j)){
        //             cnt++;
        //             ans = max(j-i+1 , ans);
        //         }
        //     }
        // }
        
        // BOTTOM UP DP APPROACH

        memset(dp, false, sizeof(dp));
        int cnt = 0;
        int ans = 0;
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len -1 < n; i++){
                int j = i+len-1;
             // for one length -->
                if(i == j) { 
                    dp[i][j] = true;
                }else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]){
                    cnt++;
                    ans = max(ans , j-i+1);
                }   
            }
        }
        cout << ans << endl;
        return cnt;
    }
};