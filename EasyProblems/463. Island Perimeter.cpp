#include<bits/stdc++.h>
using namespace std;
int islandPerimeter(vector<vector<int> >& grid) {
	int perimeter = 0;
    int length = grid[0].size();
    for(int i = 0;i<grid.size();i++){
    	for(int j = 0;j<grid[i].size();j++){
    		if(!grid[i][j]){
    			cout << "1";
    			if(grid[i-1][j] == 1 || grid[i][j-1] == 1 || grid[i+1][j] == 1 || grid[i][j+1] == 1)perimeter++;
			}
		}
		
	}
	return perimeter;
	
}
/*
[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
4
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0
*/



int main(){
	vector<vector<int> > grid;
	int size;
	int x;
	cin >> size;
	for(int i = 0;i<size;i++){
		vector<int>temp;
		for(int j = 0;j<size;j++){
			cin >> x;
			temp.push_back(x);
		}
		grid.push_back(temp);
	}
	
	cout << islandPerimeter(grid);
	
	
	return 0;
}
