class Solution {
    using ll = long long;
    ll mod = 1e9 + 7;
    ll dp[201][201][201];
    ll recursion(vector<int>&nums, int idx, ll g1, ll g2){
        if(idx < 0){
            if(g1 != 0 && g2 != 0 && g1 == g2) return 1;
            
            return 0;
        }
        
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2]%mod;

        ll choice1 = recursion(nums, idx-1, g1,g2)%mod;
        ll choice2 = recursion(nums, idx-1, gcd(g1, nums[idx]),g2)%mod;
        ll choice3 = recursion(nums, idx-1, g1,gcd(g2, nums[idx]))%mod;

        return dp[idx][g1][g2] = (choice1%mod + choice2%mod + choice3%mod)%mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return recursion(nums, n-1, 0, 0);
    }
};