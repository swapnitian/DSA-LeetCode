class Solution {
public:
    int binaryGap(int n) {
        int prev = -1 ;
        int curr = 0 ; int length = 0 ;
        while(n > 0){
            int bit = n&1 ;
            if(bit == 1 && prev == -1){
                prev = curr ;
            }else if(bit == 1 && prev != -1){
                length = max(curr-prev , length) ;
                prev = curr ;
            }
            curr++ ;
            n = n >> 1 ;
        }
        return length ;
    }
};