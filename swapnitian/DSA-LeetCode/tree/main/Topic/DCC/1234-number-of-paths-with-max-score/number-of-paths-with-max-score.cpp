class Solution {
    int mod = 1e9 + 7;
    pair<int,int> dp[101][101];
    bool check(int i, int j, vector<string>& board){
        int n = board.size();
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    int getVal(char c){
        return (c == 'S') ? 0 : c-'0';
    }

    pair<int,int> recursion(vector<string>& board, int i, int j){
        // base case
        if(board[i][j] == 'E') return {0,1};

        if(board[i][j] == 'X') return {INT_MIN,0};   

        if(dp[i][j] != make_pair(-1, -1)) return dp[i][j];

        int upscore = 0, uppath = 0;
        int leftscore = 0, leftpath = 0;
        int diagscore = 0, diagpath = 0;

        // UP ->    
        if(check(i-1, j, board)){
            auto [score, path] = recursion(board, i-1, j);
            upscore = score;
            uppath = path;

            if(uppath > 0){
                upscore += getVal(board[i][j]);
            }
        }
        // LEFT ->    
        if(check(i, j-1, board)){
            auto [score, path] = recursion(board, i, j-1);
            leftscore = score;
            leftpath = path;

            if(leftpath > 0){
                leftscore += getVal(board[i][j]);
            }
        }
        // DIAGONAL  ->    
        if(check(i-1, j-1, board)){
            auto [score, path] = recursion(board, i-1, j-1);
            diagscore = score;
            diagpath = path;

            if(diagpath > 0){
                diagscore += getVal(board[i][j]);
            }
        }

        // NOW THE MAIN THING RETURN THE BEST SCORE AND BEST PATH
        int bestscore ; int bestpath;
        if(upscore == leftscore && upscore == diagscore){
            bestscore = upscore;
            bestpath =  uppath + leftpath + diagpath;
        }else if(upscore == leftscore){
            bestscore = upscore;
            bestpath =  uppath + leftpath;

            if(diagscore > bestscore){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }else if(leftscore == diagscore){
            bestscore = leftscore;
            bestpath =  diagpath + leftpath;

            if(upscore > bestscore){
                bestscore = upscore;
                bestpath = uppath;
            }
        }else{
            bestscore = upscore; bestpath = uppath;

            if(leftscore > bestscore){
                bestscore = leftscore;
                bestpath = leftpath;
            }
            if(diagscore > bestscore){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }
        return dp[i][j] = {bestscore, bestpath%mod};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        memset(dp, -1, sizeof(dp));
        pair<int,int> ans = recursion(board, n-1, n-1);
        return {ans.first, ans.second};
    }
};