class Solution {
public:
    int minFlips(string s) {
        int n = s.size() ;
        s = s+s ;

        int flip1 = 0 ; int flip2 = 0 ;
        int ans = INT_MAX ;

        int l = 0 ;
        for(int r = 0 ; r < 2*n ; r++){
            
            if(r%2 == 0){
                if(s[r] == '1')flip1++ ;
                else flip2++ ;
            }else {
                if(s[r] == '1')flip2++ ;
                else flip1++ ;
            }
            if(r-l+1 > n){
                if(l%2 == 0){
                    if(s[l] == '1')flip1-- ;
                    else flip2-- ;
                }else {
                    if(s[l] == '1')flip2-- ;
                    else flip1-- ;
                }
                l++; 
            }
            if(r-l+1 == n){
                ans = min({ans , flip1 , flip2}) ;
            }
        }
        return ans ;
    }
};