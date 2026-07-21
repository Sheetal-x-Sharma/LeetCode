class Solution {
public:

    void shift(auto &grid, int m, int n){

        int last;
        int l;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 and j==n-1)
                last = grid[i][j];
                else if(j==n-1){
                    l = grid[i][j];
                }
                else{
                    grid[i][j+1] = grid[i][j];
                }
            }
            if(i != m-1)
            grid[i+1][0] = l;
        }

        grid[0][0] = last;
    }


    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        while(k--){
            shift(grid, m, n);
        }

        return grid;
    }
};