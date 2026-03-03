class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int,int> mp1 , mp2 ; 
        for(int i = 0 ; i < n ; i++){
            mp1[nums[i]]++ ;
        }
        for(auto it : mp1){
            mp2[it.second]++ ;
        }
        for(int i = 0 ; i < n ; i++){
            if(mp2[mp1[nums[i]]] == 1){
                return nums[i] ;
            }
        }
        return -1 ; 
    }
};