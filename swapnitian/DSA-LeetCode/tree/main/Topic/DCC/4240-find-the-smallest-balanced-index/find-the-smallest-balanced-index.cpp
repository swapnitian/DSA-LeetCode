class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size() ;
        // since it is ongoing sum so , i don't think to take vector ;
        // vector<long long>prefsum(n+1 , 0) ;
        long long prod = 1 ;
        long long prefsum = 0 ;
        for(int i = 0 ; i < n ; i++) prefsum = prefsum + nums[i] ;
        
        for(int i = n-1 ; i >= 0 ; i--){
            prefsum = prefsum - nums[i] ;
            
            if(prefsum == prod) return i ; 
            
            if(prod >=  4e15) break  ;
            prod *= nums[i] ;
        }
        return -1 ;
    }
};