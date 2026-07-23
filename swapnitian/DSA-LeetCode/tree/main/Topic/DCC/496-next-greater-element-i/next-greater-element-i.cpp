class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        stack<int> st;
        unordered_map<int,int> mp;
        
        mp[nums2[n2-1]] = -1;
        st.push(nums2[n2-1]);
        
        for(int j = n2-2; j >= 0; j--){
            if(!st.empty() && st.top() > nums2[j]){
                mp[nums2[j]] = st.top();
                st.push(nums2[j]);
            }else{
                while(!st.empty() && st.top() < nums2[j]){
                    st.pop();
                }

                mp[nums2[j]] = (st.size() > 0) ? st.top() : -1;

                st.push(nums2[j]);
            }
        } 

        vector<int> ans(n1);

        for(int i = 0; i < n1; i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};