class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());
        int num = k;
        while(st.find(k) != st.end()){
            k = k + num;
        }
        return k;
    }
};