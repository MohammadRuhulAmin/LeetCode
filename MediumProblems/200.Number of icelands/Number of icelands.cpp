class Solution {
public:
    void traverse(vector<vector<char>>&grid,int row,int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size())return ;
        if(grid[row][col] == '0')return ;
        else{
            grid[row][col] = '0';
            for(int r = row-1;r<=row+1;r++){
                for(int c = col-1;c<=col+1;c++){
                    if(abs(r-row) == 1 && abs(c-col) == 1)continue;
                    else traverse(grid,r,c);
                }
            }
            return;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j= 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                   traverse(grid,i,j);
                   ans++;
                   
                }
            }
        }
        return ans;
    }
};