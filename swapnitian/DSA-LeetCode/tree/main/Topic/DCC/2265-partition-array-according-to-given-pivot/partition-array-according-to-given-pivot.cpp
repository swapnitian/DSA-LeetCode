class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small , large;
        vector<int>ans;
        int freq = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                small.push_back(nums[i]);
            }else if(nums[i] > pivot){
                large.push_back(nums[i]);
            }else{
                freq++;
            }
        }
        for(auto it : small){
            ans.push_back(it);
        }
        while(freq--)ans.push_back(pivot);
        for(auto it : large){
            ans.push_back(it);
        }
        return ans;
    }
};