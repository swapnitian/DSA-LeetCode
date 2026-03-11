class Solution {
public:
    int bitwiseComplement(int n) {
        // 1st approach 
        int ans = 0; 
        // int cnt = 0 ;
        // while(n > 0){
        //     int bit = !(n%2) ;
        //     ans += pow(2 , cnt)*bit ;
        //     n = (n >> 1) ;
        //     cnt++ ;
        //     // cout << n << endl;
        // }
        // return ans; 

        // 2nd approach --

        // by using Bitmasking

        int mask = 1 ;
        while(mask < n){
            mask = (mask << 1) | 1 ;
        }
        return mask ^ n ;
    }
};