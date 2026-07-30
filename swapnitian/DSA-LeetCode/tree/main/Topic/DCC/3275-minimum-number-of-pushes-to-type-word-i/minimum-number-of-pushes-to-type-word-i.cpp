class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans;
        if(n <= 8){
            ans = n;
        }else if(n > 8 && n <= 16){
            ans = 8 + (n-8)*2;
        }else if(n > 16 && n <= 24){
            ans = 8 + 16 + (n-16)*3;
        }else if(n > 24 && n <= 26){
            ans = 8 + (2*8) + (3*8) + (n-24)*4;
        }
        return ans;
    }
};