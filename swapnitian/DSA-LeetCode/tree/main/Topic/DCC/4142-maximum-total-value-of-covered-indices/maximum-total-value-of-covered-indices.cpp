using ll = long long;
ll dp[100001][2];
class Solution {
    ll recursion(vector<int>&nums,string &s, int idx, bool f1){
        if(idx < 0) return 0;
        
        // in this we have option to stay or to move if the s[idx] == 1;
        if(dp[idx][f1] != -1) return dp[idx][f1];

        ll ans = 0;
        
        if(s[idx] == '0'){
            ll val1 = f1 ? nums[idx] : 0;

            ans = max(ans , val1 + recursion(nums,s,idx-1,0));
        }else {
            // not skip 
            ans = nums[idx] + recursion(nums,s,idx-1,0);
        
            if(idx > 0){
                ll val2 = f1 ? nums[idx] : 0;
                ans = max(ans , val2 + recursion(nums,s,idx-1,1));
            }
        }
        return dp[idx][f1] = ans;
    }
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return recursion(nums, s, n-1, 0);
    }
};