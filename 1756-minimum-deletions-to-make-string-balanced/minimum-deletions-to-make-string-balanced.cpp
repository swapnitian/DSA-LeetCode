class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_a = 0 ;
        int n = s.size() ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a')cnt_a++ ;
        }
        int cnt_b = 0 ;
        int ans = n ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a'){
                cnt_a-- ;
                if(cnt_b >= 0){
                    ans = min(ans, cnt_a+cnt_b) ;
                }
            }else{
                ans = min(ans , cnt_a+cnt_b) ;
                cnt_b++ ;
            }
        }
        return ans ;
    }
};