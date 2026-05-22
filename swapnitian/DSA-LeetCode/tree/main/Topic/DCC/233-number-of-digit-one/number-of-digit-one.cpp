using ll = long long;
class Solution {
ll dp[11][2][11];
string s;
ll len;
ll recursion(ll idx, ll high, ll cnt1){
    if(idx == len){
        return cnt1;
    }

    if(dp[idx][high][cnt1] != -1) return dp[idx][high][cnt1];

    ll low_limit = 0;
    ll high_limit = 9;

    if(high == 1){
        high_limit = s[idx] - '0';
    }
    ll ans = 0;
    for(int i = low_limit; i <= high_limit; i++){
        ll new_high = high;

        if(i != s[idx]-'0'){
            new_high = 0;
        }
        int new_cnt1 = cnt1;

        if(i == 1){
            new_cnt1++;
        }
        ans = ans + recursion(idx+1, new_high, new_cnt1);
    }
    return dp[idx][high][cnt1] = ans;
}
public:
    int countDigitOne(int n) {
        s = to_string(n);
        len = s.size();
        memset(dp , -1, sizeof(dp));
        return recursion(0 , 1, 0);
    }
};