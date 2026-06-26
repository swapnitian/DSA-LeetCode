class Solution {
using ll = long long;
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // in this question we use the logic of prefix sum and solved using with the help of map just observe the things we assume the val = 1 if it is target otherwise assume -1 which helps to find out the numbers that are present on the left;
        unordered_map<ll ,ll> mp;
        ll cum_sum = 0; ll validleftpoints = 0;
        int n = nums.size();
        mp[cum_sum] = 1;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                validleftpoints += mp[cum_sum];
                cum_sum++;
            }else{
                cum_sum--;
                validleftpoints -= mp[cum_sum];
            }

            ans += validleftpoints;
            mp[cum_sum]++;
        }

        return ans;
    }
};