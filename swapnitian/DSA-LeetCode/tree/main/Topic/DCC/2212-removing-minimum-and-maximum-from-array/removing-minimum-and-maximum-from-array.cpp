class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
        int idx1 = -1; int idx2 = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi) idx1 = i;
            if(nums[i] == mini) idx2 = i;
        }

        int ch1 = max(idx2, idx1)+1;
        int ch2 = n - min(idx2, idx1);
        int ch3 = min(idx1, idx2) + 1 + (n - max(idx2, idx1)); 

        int ans = min({ch1, ch2, ch3});

        return ans;
    }
};