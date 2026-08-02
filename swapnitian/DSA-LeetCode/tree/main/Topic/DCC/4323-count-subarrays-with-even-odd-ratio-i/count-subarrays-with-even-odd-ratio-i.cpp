class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int cntO = 0; int cntE = 0;
            for(int j = i; j < n; j++){
                if(nums[j]&1) cntO++;
                else cntE++;

                if(cntO > 0 && cntE*b <= cntO*a){
                    ans++;
                } 
            }
        }

        return ans;
    }
};