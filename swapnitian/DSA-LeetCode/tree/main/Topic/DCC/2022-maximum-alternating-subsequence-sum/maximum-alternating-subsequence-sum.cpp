class Solution {
using ll = long long;
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        ll even = 0;
        ll odd = 0;

        for(int i = 0; i < n; i++){
            even = max(even, odd + nums[i]);
            odd  = max(odd, even - nums[i]);
        }

        return even;
    }
};