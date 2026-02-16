class Solution {
public:
    int reverseBits(int n) {
        // in this problem we will solve by using bit manipulation technique ;
        int ans = 0 ;
        for(int i =1 ; i<= 32 ; i++){
            // (n&1) -> this will tell the last bit 
            // ans = ans|(n&1) adding the last bit into answer ;
            // >> right shift << left shift     
            ans = ans << 1 ;    
            ans = ans|(n&1) ;
            n = n >> 1 ;
        }
        return ans ;
    }
};