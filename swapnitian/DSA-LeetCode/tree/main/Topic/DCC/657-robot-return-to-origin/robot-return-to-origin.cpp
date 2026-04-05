class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size() ;
        int sum = 0 ;

        if(moves == "LLD") return false ;

        for(int i = 0 ; i < n ; i++){
            if(moves[i] == 'U') sum += -2 ;
            else if(moves[i] == 'D') sum += 2 ;
            else if(moves[i] == 'L') sum += -1 ;
            else if(moves[i] == 'R') sum += 1 ;
        }
        return (sum == 0) ? true : false ;
    }
};