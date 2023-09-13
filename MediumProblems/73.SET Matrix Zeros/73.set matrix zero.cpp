class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int,int>>zeroPosition;
    for(int i = 0;i<matrix.size();i++){
    	for(int j = 0;j<matrix[i].size();j++){
    		if(matrix[i][j] == 0){
    			pair<int,int>temp;
    			temp.first = i;
    			temp.second = j;
    			zeroPosition.push_back(temp);
			}
		}
	}
    
	for(const auto& ite:zeroPosition){
		for(int x = 0;x<matrix.size();x++){
			matrix[x][ite.second] = 0;
		}
		for(int x = 0;x<matrix[0].size();x++){
			matrix[ite.first][x] = 0;
		}
	}
}
};