class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size() ;
        int l = 0 ; 
        long long ans = 0 ;
        multiset<long long> m ;
        
        for(int r = 0 ; r < n ; r++){
            m.insert(nums[r]) ;

            while(r > l && ((*m.rbegin()-*m.begin())*(1LL*m.size())) > k){
                m.erase(m.find(nums[l])) ; // delete the left until our coditions satisfied
                l++ ;
            }
            ans += (r-l+1) ; // this will count the subarrays not elements
        }
        return ans ;
    }
};