class Solution {
public:
    int dfsTraversal(vector<vector<int>>&grid,int row,int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size())return 0;
        if(grid[row][col] == 0)return 0;
        else{
            int size = 1;
            grid[row][col] = 0;
            for(int r = row-1;r<=row+1;r++){
                for(int c = col-1;c<=col+1;c++){
                    if(abs(r-row) == 1 && abs(c-col) == 1)continue;
                    else size += dfsTraversal(grid,r,c);
                }
            }
            return size;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    ans = max(dfsTraversal(grid,i,j),ans);
                }
            }
        }
        return ans;
    }
};