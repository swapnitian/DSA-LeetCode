class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1 ;

        for(int i = 0 ; i < 32 ; i++){
            if((n >> i) == 0) break ;

            int curr = ((n >> i) & 1) ; 
        
            if(prev == -1){
                prev = curr ;
                continue ;
            }
            if(curr == prev) return false ;
        
            prev = curr ;
        }
        return true ;
    }
};