class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& nums) {
        vector<int> status (101 , 0) ;

        for(int i = 0 ; i < nums.size() ; i++){
            if(status[nums[i]] == 0){
                status[nums[i]] = 1; 
            }else{
                status[nums[i]] = 0 ;
            }
        }
        vector<int> ans ;
        for(int i = 1 ; i <= 100 ; i++){
            if(status[i]) ans.push_back(i) ;
        }
        return ans ;
    }
};