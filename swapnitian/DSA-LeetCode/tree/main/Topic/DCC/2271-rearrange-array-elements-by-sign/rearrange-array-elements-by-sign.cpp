class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos , neg;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                pos.push(nums[i]);
            }else{
                neg.push(nums[i]);
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(i&1){
                ans[i] = neg.front();
                neg.pop();
            }else{
                ans[i] = pos.front();
                pos.pop();
            }
        }

        return ans;
    }   
};