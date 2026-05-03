class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // will try to calculate the closest ;

        vector<int>closest(n); // in this 0 > left , 1 -> right 
        closest[0] = 1;
        closest[n-1] = 0;
        for(int i = 1; i < n-1; i++){
            int ld = abs(nums[i] - nums[i-1]);
            int rd = abs(nums[i] - nums[i+1]);

            if(ld <= rd){
                closest[i] = 0;
            }else{
                closest[i] = 1;
            }
        }
        // precalculate the directions---

        vector<int> prefl(n , 0);
        vector<int> prefr(n , 0);
        for(int i = n-1 ; i > 0 ; i--){
            if(closest[i] == 0){
                prefl[i-1] = prefl[i] + 1;
            }else{
                prefl[i-1] = prefl[i] + abs(nums[i] - nums[i-1]);
            }
        }
        for(int i = 0 ; i < n-1 ; i++){
            if(closest[i] == 1){
                prefr[i+1] = prefr[i] + 1;
            }else{
                prefr[i+1] = prefr[i] + abs(nums[i+1] - nums[i]);
            }
        }
        vector<int> ans(queries.size()) ;

        for(int i = 0 ; i < queries.size() ; i++){
            int l = queries[i][0];
            int r = queries[i][1];
        
            if(l <= r){
                ans[i] = abs(prefr[r] - prefr[l]);
            }else{
                ans[i] = abs(prefl[l] - prefl[r]);
            }
        }
        return ans;
    }
};