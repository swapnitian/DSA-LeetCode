class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size() ;
        vector<int> cnt(2 , 0) ;
        for(char c : t){
            cnt[c-'0']++ ;
        }
        cout << cnt[0] << " " << cnt[1] << endl;
        string ans = "" ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                if(cnt[1] > 0){
                    ans += '1' ;
                    cnt[1]-- ;
                }else{
                    ans += '0' ;
                    cnt[0]-- ;
                }
            }else{
                if(cnt[0] > 0){
                    ans += '1' ;
                    cnt[0]-- ;
                }else{
                    ans += '0' ;
                    cnt[1]-- ;
                }
            }
        }
        return ans ;
    }
};