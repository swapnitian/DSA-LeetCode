class Solution {
public:
    int minFlips(string s) {
        int n = s.size() ;
        s = s+s ;

        int flip1 = 0 ; int flip2 = 0 ;
        int ans = INT_MAX ;

        int l = 0 ;
        for(int r = 0 ; r < 2*n ; r++){
            char c1 = (r%2 == 0) ? '0' : '1' ; // start with  010101...
            char c2 = (r%2 == 0) ? '1' : '0' ; // start with 101010....

            if(s[r%n] != c1) flip1++ ;

            if(s[r%n] != c2) flip2++ ;

            if(r-l+1 > n){
                char c1 = (l%2 == 0) ? '0' : '1' ; // start with  010101...
                char c2 = (l%2 == 0) ? '1' : '0' ; // start with 101010....

                if(s[l] != c1) flip1-- ;
                if(s[l] != c2) flip2-- ;

                l++ ;
            }
            if(r-l+1 == n){
                ans = min({ans , flip1 , flip2}) ;
            }
        }
        return ans ;
    }
};