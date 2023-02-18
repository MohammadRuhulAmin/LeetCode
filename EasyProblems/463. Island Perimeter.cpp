#include<bits/stdc++.h>
using namespace std;
int islandPerimeter(vector<vector<int> >& grid) {
	int perimeter = 0;
	int size = grid[0].size();
	for(int i = 0;i<size;i++){
		if(grid[0][i] == 1)perimeter++;
	}
	for(int i = 0;i<size;i++){
		if(grid[i][0] == 1)perimeter++;
	}
	for(int i = 0;i<size;i++){
		if(grid[size-1][i] == 1)perimeter++;
	}
	for(int i = 0;i<size;i++){
		if(grid[i][size-1] == 1)perimeter++;
	}
	
	
	for(int i = 0;i<size;i++){
		for(int j = 0;j<size;j++){
			if(grid[i][j] == 0){
				if( i-1>=0 && grid[i-1][j] == 1)perimeter++;
				if(i+1<size && grid[i+1][j] == 1)perimeter++;
				if(j-1>=0 && grid[i][j-1] == 1)perimeter++;
				if(j+1<size && grid[i][j+1] == 1)perimeter++;
			}
		}
	}
	

	
	return perimeter;
	
}
/*
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
