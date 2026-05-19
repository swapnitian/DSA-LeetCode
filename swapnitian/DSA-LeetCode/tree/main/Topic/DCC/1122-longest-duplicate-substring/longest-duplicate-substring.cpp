using ll = long long;
ll p1 = 31; ll p2 = 37;
ll mod1 = 1e9 + 7; ll mod2 = 1e9 + 9;

class Solution {
void get_hash(vector<ll>&pref, vector<ll>&power, string &s, ll p, ll mod){
    int n = s.size();
    power[0] = 1;
    for(int i = 1; i < n; i++){
        power[i] = (power[i-1] * p) % mod;
    }
    // pref array
    for(int i = 0; i < n; i++){
        ll val = s[i] - 'a' + 1;

        pref[i] = (val * power[i]) % mod;

        if(i > 0){
            pref[i] = (pref[i-1] + pref[i] + mod) % mod;
        }
    } 
}
ll check(vector<ll>&pref1,vector<ll>&pref2, vector<ll>&power1,vector<ll>&power2, ll k, ll mod1 , ll mod2){
    
    int n = pref1.size();
    
    set<pair<ll , ll>> st;

    for(int i = 0; i < n-k+1; i++){
        int j = i + k - 1;

        ll hash1 = pref1[j];
        ll hash2 = pref2[j];

        if(i > 0){
            hash1 = (hash1 - pref1[i-1] + mod1) % mod1;
            hash2 = (hash2 - pref2[i-1] + mod2) % mod2;
        }
        // most important step that is normalization --
        hash1 = (hash1 * power1[n -i -1]) % mod1; 
        hash2 = (hash2 * power2[n -i -1]) % mod2; 

        pair<ll,ll> hash = {hash1 , hash2};

        if(st.count(hash)){
            return i;
        }
        st.insert(hash);
    }
    return -1;
}
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<ll> pref1(n) , pref2(n);
        vector<ll> power1(n) , power2(n);

        get_hash(pref1, power1, s, p1, mod1);
        get_hash(pref2, power2, s, p2, mod2);

        ll maxi = 0;
        ll idx_ans; 
        ll st = 1; ll end = n-1;

        while(st <= end){
            ll mid = st + (end-st)/2;

            ll idx = check(pref1, pref2, power1, power2, mid, mod1, mod2);

            if(idx != -1){
                maxi = mid;
                idx_ans = idx; 
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        if(maxi == 0) return "";

        string ans = s.substr(idx_ans , maxi);
        
        return ans;
    }
};