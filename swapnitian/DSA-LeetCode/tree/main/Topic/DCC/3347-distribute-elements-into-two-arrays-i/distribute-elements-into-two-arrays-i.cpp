class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        int lt = 0; int rt = n-1;
        
        ans[lt] = nums[0];
        ans[rt] = nums[1];

        for(int i = 2; i < n; i++){
            if(ans[lt] > ans[rt]){
                ans[lt+1] = nums[i];
                lt++;
            }else{
                ans[rt-1] = nums[i];
                rt--;
            }
        }
        reverse(ans.begin()+rt, ans.end());
        return ans;
    }
};