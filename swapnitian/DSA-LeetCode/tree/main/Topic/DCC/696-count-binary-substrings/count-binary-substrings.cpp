class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size() ;
        int cnt1 = 0 ; int cnt2 = 0 ; 
        char c = s[0] == '0' ? '0' : '1' ;
        int ans = 0 ;
        // for(int i = 0 ; i < n ; i++){
        //     if(s[i] == c){
        //         cnt1++ ;
        //         if(cnt2 > 0){
        //             ans++ ;
        //             cnt2-- ;
        //         }
        //         if(s[i] != s[i+1]) cnt2 = 0 ;
        //     }
        //     else{
        //         cnt2++ ;
        //         if(cnt1 > 0){
        //             ans++ ;
        //             cnt1-- ;
        //         }
        //         if(s[i] != s[i+1])cnt1 = 0; 
        //     }
        // }
        // return ans ;


        // 2nd approach by grouping

        int prev = 0 ; int curr = 1 ;

        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]) curr++ ;
            else{
                ans += min(prev , curr) ;

                prev = curr ;
                curr = 1 ;
            }
        }
        // edge case what if 0011 ; 
        ans += min(prev , curr) ;

        return ans ;
    }   
};