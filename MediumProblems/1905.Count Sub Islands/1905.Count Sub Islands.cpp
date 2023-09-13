class Solution {
public:
    void dfsTraversal(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int row,int col,bool &flag){
        if(row<0 || col <0 || row>=grid2.size() || col >=grid2[0].size())return ;
        if(grid2[row][col] == 0)return ;
        else{
            if(grid1[row][col] == 0){
                flag = false;
                return;
            }
            grid2[row][col] = 0;
            for(int r = row-1;r<=row+1;r++){
                for(int c = col-1;c<=col+1;c++){
                    if(abs(r-row) == 1 && abs(c-col) == 1)continue;
                    dfsTraversal(grid1,grid2,r,c,flag);
                }
            }
            return ;
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for(int i = 0;i<grid2.size();i++){
            for(int j = 0;j<grid2[i].size();j++){
                if(grid2[i][j]){
                	bool flag = true;
                    dfsTraversal(grid1,grid2,i,j,flag);
                    if(flag)ans++;
                }
            }
        }
        return ans;
    }

};