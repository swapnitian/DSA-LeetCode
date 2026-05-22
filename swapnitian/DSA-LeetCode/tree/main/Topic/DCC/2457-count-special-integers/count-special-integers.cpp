using ll = long long;
class Solution {
string s;
ll len;

ll dp[11][2][2][1025];  

ll recursion(ll idx, ll high, ll started, ll mask){
    if(idx == len){
        return started;
    }

    if(dp[idx][high][started][mask] != -1) return dp[idx][high][started][mask];

    ll low_limit = 0; 
    ll high_limit = 9; 

    if(high == 1){
        high_limit = s[idx]-'0';
    }
    ll ans = 0;

    for(int i = low_limit; i <= high_limit; i++){
        ll new_high = high;

        if(i != s[idx]-'0'){
            new_high = 0;
        }

        if(started == 0 && i == 0){
            ans = ans + recursion(idx+1, new_high, 0, mask);
        }else{
            if(mask & (1 << i)){
                continue;
            }

            ll new_mask = mask | (1 << i);

            ans = ans + recursion(idx+1, new_high, 1, new_mask);

        }
    }
    return dp[idx][high][started][mask] = ans;
}   

public:
    int countSpecialNumbers(int n) {
        s = to_string(n);
        len = s.size();
        memset(dp , -1, sizeof(dp));

        return recursion(0,1,0,0);
    }   
};