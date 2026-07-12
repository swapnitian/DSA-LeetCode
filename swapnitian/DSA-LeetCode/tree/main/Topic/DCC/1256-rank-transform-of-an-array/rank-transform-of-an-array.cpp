class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        vector<int> v;
        for(auto it : arr){
            if(st.find(it) == st.end()){
                st.insert(it);
                v.push_back(it);
            }
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

            ans[i] = idx+1;
        }
        return ans;
    }
};