class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cntL = 0; 
        int cntR = 0;

        for(int i = 0; i < n; i++){
            if(moves[i] == 'R')cntR++ ;
            else if(moves[i] == 'L')cntL++ ;
        }
        
        int ans = max(cntL , cntR)+(n-(cntL+cntR)) - min(cntL , cntR);

        return ans;
    }
};