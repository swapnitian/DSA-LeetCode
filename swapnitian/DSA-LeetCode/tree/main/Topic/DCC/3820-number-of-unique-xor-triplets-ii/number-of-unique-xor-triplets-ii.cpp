class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n  = nums.size();
        unordered_set<int> dual , triple;
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ;j<n ;j++){
                dual.insert(nums[i]^nums[j]);
            }
        }
        for(int x : dual){
            for(int num : nums){
                triple.insert(x^num);
            }
        }
        return triple.size();
    }
};