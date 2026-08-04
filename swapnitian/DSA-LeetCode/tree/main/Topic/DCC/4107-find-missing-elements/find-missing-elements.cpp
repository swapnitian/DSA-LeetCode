class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
    
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        while(mini <= maxi){
            if(s.find(mini) == s.end()) ans.push_back(mini);

            mini++;
        }   

        return ans;
    }
};