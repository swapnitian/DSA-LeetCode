class Solution {
    int val = 0;
    void recursion(vector<vector<int>>&grid, int rowstart, int rowend,int colst,
                     int colend){
        int size = rowend-rowstart;

        if(size == 1){
            grid[rowstart][colst] = val;
            val++;
            return;
        }
        
        int midrow = rowstart + size/2;
        int midcol = colst + size/2;

        // top right =->
        recursion(grid, rowstart, midrow, midcol,colend);
        // bottom right ->
        recursion(grid, midrow, rowend, midcol, colend);
        // bottom left ->
        recursion(grid, midrow, rowend, colst, midcol);
        // top left ->
        recursion(grid, rowstart, midrow, colst, midcol);
    }
public:
    vector<vector<int>> specialGrid(int n) {
        int N = 1 << n;
        vector<vector<int>> grid(N , vector<int>(N));
        recursion(grid, 0 , N , 0 , N);

        return grid;
    }
};