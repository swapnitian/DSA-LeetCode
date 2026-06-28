class Solution {
using ll = long long;
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int idx = nums.size()-1; // last idx as we have to find the largest

        ll TotalSum = 0;
        while(k-- && idx >= 0){
            if(mul > 0) TotalSum += 1LL*mul*nums[idx];
            else TotalSum += nums[idx];

            idx--; 
            mul--;
        }

        return TotalSum;
    }
};