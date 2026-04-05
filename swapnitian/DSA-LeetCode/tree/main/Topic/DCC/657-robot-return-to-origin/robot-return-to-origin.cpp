class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size() ;
        int x = 0 , y = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(moves[i] == 'U') y += 1 ;
            else if(moves[i] == 'D') y += -1 ;
            else if(moves[i] == 'L') x += -1 ;
            else if(moves[i] == 'R') x += 1 ;
        }
        return (x == 0 && y == 0) ? true : false ;
    }
};