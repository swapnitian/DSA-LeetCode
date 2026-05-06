class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
    
        vector<vector<char>> ans(n , vector<char>(m , '.'));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[j][m-i-1] = boxGrid[i][j];
            }
        }
        
        for(int j = 0 ; j < m ; j++){
            int t = n-1;
            for(int i = n-1 ; i >= 0; i--){
                if(ans[i][j] == '#'){
                    ans[i][j] =  ans[t][j];
                    ans[t][j] =  '#';
                    t--;
                }else if(ans[i][j] == '*'){
                    t = i-1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ans[i][j] << " " ;
            }
            cout << endl;
        }

        return ans;
    }
};