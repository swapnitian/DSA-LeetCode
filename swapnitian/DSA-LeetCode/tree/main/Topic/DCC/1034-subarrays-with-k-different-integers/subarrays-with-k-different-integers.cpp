class Solution {
private:
    int solve(vector<int>&nums , int k){
        int n = nums.size() ;
        int l = 0 ; int cnt = 0 ;
        unordered_map<int,int> mpp ;
        
        for(int r = 0 ; r < n; r++){
            mpp[nums[r]]++ ;

            while(mpp.size() > k){
                mpp[nums[l]]-- ;

                if(mpp[nums[l]] == 0) mpp.erase(nums[l]) ;

                l++ ;
            }
            cnt += (r-l+1) ;
        }
        return cnt ;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k-1) ;
    }
};