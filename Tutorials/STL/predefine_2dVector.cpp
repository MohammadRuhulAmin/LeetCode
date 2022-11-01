#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int row,col;
	cin >> row >> col;
	vector<vector<int> > matrix(row,vector<int>(col));
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
