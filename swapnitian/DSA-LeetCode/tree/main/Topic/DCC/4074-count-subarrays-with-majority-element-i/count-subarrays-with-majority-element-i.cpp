class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(target == nums[j]) cnt++;

                int sz = (j-i+1)/2;
                if(cnt > sz) ans++;
            }
        }
        return ans;
    }
};