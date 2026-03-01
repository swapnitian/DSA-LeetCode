class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map< int,int> m ;
        int n = nums.size() ;
        set<int>s;
        sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i < n ; i++){
            m[nums[i]]++ ;
            s.insert(nums[i]) ;
        }
        s.erase(nums[0]) ;
        for(auto it : s){
            if(m[it] != m[nums[0]]) return {nums[0] , it} ;
        }
        return {-1, -1} ;
    }
};