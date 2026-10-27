class Solution {
public:
    vector<string> createGrid(int m, int n) {
        if(m == 1 || n == 1){
            vector<string> ans(m, string(n, '.'));
            return ans;
        }
        vector<string> ans(m, string(n, '#'));

        for(int j = 0; j < n; j++){
            ans[0][j] = '.';
        }
        for(int i = 0; i < m; i++){
            ans[i][n-1] = '.';
        }

        return ans;
    }
};