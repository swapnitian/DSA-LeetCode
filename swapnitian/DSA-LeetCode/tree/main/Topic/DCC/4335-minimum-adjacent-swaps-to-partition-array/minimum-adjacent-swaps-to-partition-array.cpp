class Solution {
using ll = long long;
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        ll ans = 0;
        
        ll first = 0; ll second = 0; ll third = 0; 
        ll mod = 1e9 + 7;
        
        for(int i = 0; i < n; i++){
            if(nums[i] < a){
                ans += second + third;
                first++;
            }else if(nums[i] >= a && nums[i] <= b){
                ans += third;
                second++;
            }else if(nums[i] > b){
                third++;
            }
        }
        return ans%mod;
    }
};