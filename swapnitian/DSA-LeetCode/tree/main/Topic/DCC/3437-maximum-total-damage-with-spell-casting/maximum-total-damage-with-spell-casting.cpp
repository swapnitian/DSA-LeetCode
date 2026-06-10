class Solution {
using ll = long long;
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<ll,ll> mp;
        for(int i = 0; i < n; i++){
            mp[power[i]] += power[i];
        }
        vector<ll> nums;
        for(auto it : mp){
            nums.push_back(it.first);
        }
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        vector<ll> dp(sz+ 1, 0);

        for(int idx = sz-1; idx >= 0; idx--){
            ll nxt = upper_bound(nums.begin(), nums.end(), nums[idx]+2) - nums.begin();

            ll take = mp[nums[idx]*1LL] + dp[nxt];

            ll not_take = dp[idx+1];

            dp[idx] = max(take , not_take);
        }
        return dp[0];
    }
};