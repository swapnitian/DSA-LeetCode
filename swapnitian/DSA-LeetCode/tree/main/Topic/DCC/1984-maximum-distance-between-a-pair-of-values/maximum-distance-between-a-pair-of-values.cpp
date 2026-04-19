class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0 , j = 0;
        int ans = INT_MIN;
        // will use two pointer

        while(i < n && j < m) {
            if(nums1[i] > nums2[j]){
                i++;
            }else if(nums1[i] <= nums2[j]) {
                ans = max(ans , j-i);
                j++;
            }
        }
        return ans < 0 ? 0 : ans;
    }
};