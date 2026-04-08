class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size() ;
        vector<long long> copy ;

        for(long long val : nums){
            copy.push_back(val) ;
        }
        int idx , ri , ki , vi ;

        long long mod = 1000000007 ;

        for(int i = 0 ; i < queries.size() ; i++){
            idx = queries[i][0] ;
            ri =  queries[i][1] ;
            ki =  queries[i][2] ;
            vi =  queries[i][3] ;

            while(idx <= ri){
                copy[idx] = (1LL*(copy[idx] * vi)) % (mod) ;
                idx += ki ;
            }
        }

        int x = 0 ;
        for( int val : copy){
            x ^= val ;
        }
        return x ;
    }
};