class Solution {
using ll = long long;
ll mod = 1e9 + 7;
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);

        for(int i = 0; i < n; i++){
            int idx = 0;
            int val = nums[i];
            while(val > 0){
                int bit = val%2;
                val = val >> 1;
                bits[idx] += bit;
                idx++;
            }
        }
        ll ans = 0;
        while(k--){
            ll num = 0;
            for(int i = 0; i < 32; i++){
                if(bits[i] > 0){
                    num += (1 << i);
                    bits[i] -= 1;
                }
            }
            ans = (ans + num*num)%mod;
        }
        return ans;
    }
};