class Solution {
public:
    int mod = 1e9 + 7 ;
    int concatenatedBinary(int n) {
        long long ans = 0 ;
        int digits = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if((i &(i-1)) == 0) digits++ ;

            ans = ((ans << digits)+ i )%mod ;
        }        
        return ans ;
    }
};