class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> list(101);
    
        for(int i = 0; i < n; i++){
            list[nums[i]].push_back(i);
        }

        int ans = 0;
        for(int i = 1; i < 101; i++){
            if(list[i].size() < 3 || list[i].size() > 3) continue;

            int d1 = list[i][1] - list[i][0]; 
            int d2 = list[i][2] - list[i][1]; 
        
            if(d1 == d2) ans++;
        }

        return ans;
    }
};