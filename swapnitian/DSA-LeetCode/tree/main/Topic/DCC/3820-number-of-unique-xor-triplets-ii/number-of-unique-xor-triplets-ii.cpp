class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st1, st2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                st1.insert(nums[i]^nums[j]);
            }
        }

        for(int k = 0; k < n; k++){
            for(auto it : st1){
                st2.insert(it^nums[k]);
            }
        }

        return st2.size();
    }
};