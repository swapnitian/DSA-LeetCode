class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int idx1 = 0 ; int idx2 = 0;

        while(idx1 < n1 && idx2 < n2){
            if(nums1[idx1] == nums2[idx2]) return nums1[idx1];

            if(nums1[idx1] < nums2[idx2]){
                idx1++;
            }else{
                idx2++;
            }
        }
        return -1;
    }
};