class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cnt = 0;
        int ans = cnt;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'R')cnt++;
            else if(moves[i] == 'L')cnt--;
            else cnt--;
        }
        ans = abs(cnt);
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'L') cnt--;
            else if(moves[i] == 'R')cnt++;
            else cnt++;
        }
        return abs(max(ans , cnt));
    }
};