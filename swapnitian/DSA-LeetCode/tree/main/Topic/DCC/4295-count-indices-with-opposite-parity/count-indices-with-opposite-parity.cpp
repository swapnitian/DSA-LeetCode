class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            int cntO = 0 ; int cntE = 0 ;
            for(int j = i+1 ; j < n ; j++){
                if(nums[j]&1)cntO++;
                else cntE++;
            }
            if(nums[i]&1) ans[i] = cntE;
            else ans[i] = cntO;
        }
        return ans;
    }
};