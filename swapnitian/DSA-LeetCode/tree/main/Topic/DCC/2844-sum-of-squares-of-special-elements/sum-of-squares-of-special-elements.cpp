class Solution {
using ll = long long;
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        for(int i = 1; i <= n; i++){
            ans += (n%i == 0) ? nums[i-1]*nums[i-1] : 0;
        }

        return ans;
    }
};