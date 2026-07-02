class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1) health--;

        vector<vector<int>> H(n, vector<int>(m, INT_MIN));
        H[0][0] = health;   

        deque<pair<pair<int,int>,int>> dq;
        dq.push_front({{0 , 0}, health});
    
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!dq.empty()){
            int row = dq.front().first.first;
            int col = dq.front().first.second;
            int wt  = dq.front().second;
            dq.pop_front();

            for(int i = 0; i < 4; i++){
                int nrow = dr[i] + row;
                int ncol = dc[i] + col;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[nrow][ncol] == 1){
                        if(wt-1 > H[nrow][ncol]){
                            H[nrow][ncol] = wt-1;
                            dq.push_back({{nrow, ncol}, wt-1});
                        }
                    }else{
                        if(wt > H[nrow][ncol]){
                            H[nrow][ncol] = wt;
                            dq.push_front({{nrow, ncol}, wt});
                        }
                    }
                }
            }
        }
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << H[i][j] << " ";
            }
            cout << endl;
        }


        return (H[n-1][m-1] > 0 ? true : false);
    }
};