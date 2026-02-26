class Solution {
public:
    int numSteps(string s) {
        int n = s.size() ;

        int ans = 0 ;
        int carry = 0 ;

        for(int i = n-1 ; i > 0 ; i--){
            int bit = s[i]-'0' ;
            if((bit+carry)%2){
                ans += 2 ;
                carry = 1 ;
            }else{
                ans += 1 ;
            }
        }
        return carry != 0 ? carry + ans : ans ;
    }
};