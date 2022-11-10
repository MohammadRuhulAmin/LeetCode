#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int row,col;
	cin >> row >> col;
	vector<vector<int> > matrix(row,vector<int>(col)); // the 2d matrix all elements will be 0 
	
	vector<vector<int> > xtrix(row,vector<int>(col,1)) // the 2d matrix all elements will be 1 
	
	
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
