class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());

        int sz = st.size();

        auto it = st.begin();
        int cnt = 1;
        int lcs = 0;
        while(sz--){
            if(st.find(*it + 1) != st.end()){
                cnt++;
            }else{
                cnt = 1;
            }
            lcs = max(lcs, cnt);
            it++;
        }

        return lcs;
    }
};