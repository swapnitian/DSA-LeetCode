class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int inv_cnt = 0;
        
        if(nums[0] < nums[n-1]) inv_cnt++;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]) inv_cnt++;
        } 
        return (inv_cnt <= 1);
    }  
};