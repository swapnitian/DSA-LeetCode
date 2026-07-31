class Solution {
    int Count_Subarrays(vector<int>&nums, int k){
        unordered_map<int,int> mp;
        int n = nums.size();

        int cnt_Subarrays = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            
            cnt_Subarrays += (r-l+1);
        }

        return cnt_Subarrays;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Count_Subarrays(nums, k) - Count_Subarrays(nums, k-1);
    }
};