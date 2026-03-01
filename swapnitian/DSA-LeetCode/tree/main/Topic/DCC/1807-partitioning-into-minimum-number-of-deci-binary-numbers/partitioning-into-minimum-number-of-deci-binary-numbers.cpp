class Solution {
public:
    int minPartitions(string n) {
        int s = n.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < s ; i++){
            ans = max(ans , n[i]-'0') ;
        }
        return ans ;
    }
};