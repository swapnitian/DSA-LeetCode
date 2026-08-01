class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n);
        diff[0] = nums[0];

        for(int i = 1; i < n; i++){
            diff[i] = nums[i] - nums[i-1];
        }

        for(auto query: queries){
            int l = query[0];
            int r = query[1];
        
            diff[l] -= 1;

            if(r+1 < n) diff[r+1] += 1;
        }
        nums[0] = diff[0];

        if(nums[0] > 0) return false;

        for(int i = 1; i < n; i++){
            nums[i] = nums[i-1] + diff[i];

            if(nums[i] > 0) return false; 
        }

        return true;
    }
};