using ll = long long;
ll mod = 1e9 + 7;
class Solution {
void get_hash(vector<int> &nums , vector<ll>&pref , vector<ll>&power){
    int n = nums.size();
    ll p = 31;
    ll mod = 1e9 + 7;
    power[0] = 1;

    for(int i = 1; i < n; i++){
        power[i] = (power[i-1] * p) % mod;
    }

    // prefix hash
    for(int i = 0; i < n; i++){
        pref[i] = (nums[i] * power[i]) % mod;

        if(i > 0){
            pref[i] = (pref[i] + pref[i-1] + mod) % mod;
        }
    }
}
bool count_distinct_substring(vector<ll>&pref , vector<ll>&power , int mid){
    unordered_map<ll,ll>mp;
    int n = pref.size();
    for(int i = 0; i < n - mid + 1; i++){
        int j = i + mid - 1;

        ll hash = pref[j];

        if(i > 0){
            hash = (hash - pref[i-1] + mod)% mod;
        }
        // normalization 

        hash = (hash * power[n-i-1]) % mod;

        mp[hash]++;
    }
    for(auto it : mp){
        if(it.second == 1) return true;
    }
    return false;
}
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n) , power(n);

        get_hash(nums , pref , power);

        for(auto it : pref){
            cout << it << " ";
        }
        int st = 1; int end = n;
        int ans = n;
        while(st <= end){
            int mid = st + (end-st)/2;

            bool check = count_distinct_substring(pref, power , mid);
            if(check){
                ans = min(ans , mid);
                end = mid -1;
            }else{
                st = mid + 1;
            }
        }

        return ans;
    }
};