class Solution {
using ll = long long;
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll total_sum = 0;
        ll left_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        
            if(i < n/2) left_sum += nums[i];
        }

        int lt = -1; int rt = n/2-1;
        ll right_sum = 0;
        int cnt = 0;
        while(rt < n-1){
            if(lt != -1){
                left_sum = left_sum + nums[rt] - nums[lt];
            }
            right_sum = total_sum - left_sum;

            if(left_sum > right_sum || right_sum > left_sum) cnt++;

            rt++; 
            lt++;
        }
        return cnt;
    }
};