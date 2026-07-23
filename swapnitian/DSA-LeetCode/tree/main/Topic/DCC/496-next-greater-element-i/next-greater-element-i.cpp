class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans(n1);
        for(int i = 0; i < n1; i++){
            stack<int> st;

            for(int j = n2-1; j >= 0; j--){
                if(nums2[j] == nums1[i]) break;

                if(nums2[j] > nums1[i]) st.push(nums2[j]);
            }
            ans[i] = (st.empty()) ? -1 : st.top();
        }

        return ans;
    }
};