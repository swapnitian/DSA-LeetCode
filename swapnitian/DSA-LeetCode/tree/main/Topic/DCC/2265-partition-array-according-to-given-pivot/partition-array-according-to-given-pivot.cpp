class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int st = 0; int end = n-1;
        int p1 = 0; int p2 = n-1;
        while(st < n){
            if(nums[st] < pivot){
                ans[p1] = nums[st];
                p1++;
            }
            if(nums[end] > pivot){
                ans[p2] = nums[end];
                p2--;
            }
            st++ ; end--;
        }
        while(p1 <= p2){
            ans[p1] = pivot;
            p1++;
        }
    
        return ans;
    }
};