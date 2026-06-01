class Solution {
bool dp[1001][1001];
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
        int cnt = 0;
        memset(dp, false, sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(s, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};