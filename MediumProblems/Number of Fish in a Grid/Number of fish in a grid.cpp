class Solution {
public:
int traverse(vector<vector<int>>&grid,int row,int col){
        if(row<0 || col < 0 || row>=grid.size() || col>=grid[0].size())return 0;
        if(grid[row][col] == 0)return 0;
        else{
        	int temp_ans = grid[row][col];
            grid[row][col] = 0;
            for(int r = row-1;r<=row+1;r++){
                for(int c = col-1;c<=col+1;c++){
                    if(abs(r-row) == 1 && abs(c-col) == 1)continue;
                    else temp_ans += traverse(grid,r,c); 
                }
            }
            return temp_ans;
        }
    }


int findMaxFish(vector<vector<int>>&grid){
	int ans = 0;
	for(int i = 0;i<grid.size();i++){
		for(int j = 0;j<grid[0].size();j++){
			if(grid[i][j]>0){
				ans = max(traverse(grid,i,j),ans);
			}
		}
	}
	return ans;
}
};