class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return nums;

        vector<int> suffix_min(n , 0);
        vector<int> ans;
        ans.push_back(nums[0]);
        suffix_min[n-1] = nums[n-1];

        for(int i = n-2 ; i >=0 ; i--){
            suffix_min[i] = max(suffix_min[i+1] , nums[i]);
        }
        int prefix_max = nums[0];
        for(int i = 1; i < n-1; i++){
            if(nums[i] > prefix_max || nums[i] > suffix_min[i+1]){
                ans.push_back(nums[i]);
            }
            prefix_max = max(prefix_max , nums[i]);
        }
        ans.push_back(nums[n-1]);

        return ans;
    }
};