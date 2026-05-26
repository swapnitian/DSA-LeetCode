class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n = nums.size();
        st.push({nums[n-1] , n-1});

        vector<int> ans(n,0);
        for(int i = n-2; i >= 0; i--){
            int days = 0;
            while(!st.empty() && nums[i] >= st.top().first) st.pop();

            if(!st.empty()){
                days = st.top().second;
            }
            if(days != 0){
                ans[i] = days - i;
            }

            st.push({nums[i] , i});
        }
        return ans;
    }
};