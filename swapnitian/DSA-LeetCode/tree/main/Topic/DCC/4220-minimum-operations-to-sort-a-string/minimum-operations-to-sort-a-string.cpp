class Solution {
    bool check (string &s){
        int n = s.size();
        for(int i = 0; i < n-1; i++){
            if(s[i] > s[i+1]) return false;
        }
        return true;
    }
    int count (char c, string &s){
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == c) cnt++;
        }
        return cnt;
    }
public:
    int minOperations(string s) {
        int n = s.size();

        if(check(s)) return 0;

        if(n == 2) return (s[0] < s[1]) ? 0 : -1;

        int minc = -1;
        int maxc = -1;

        char maxi = 'a'; char mini = 'z';

        for(int i = 0; i < n; i++){
            if(s[i] <= mini){
                mini = s[i];
                minc = i;
            }
            if(s[i] >= maxi) {
                maxi = s[i];
                maxc = i;
            }
        }

        int cntmin = count(mini, s); int cntmax = count(maxi, s);

        if(s[0] == mini || s[n-1] == maxi) return 1;
        else if(maxc == 0 && minc == n-1 && cntmin < 2 && cntmax < 2) return 3;

        return 2;
    }
};