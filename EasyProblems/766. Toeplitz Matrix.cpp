#include<bits/stdc++.h>
using namespace std;

bool isToeplitzMatrix(vector<vector<int> >& matrix) {
    int col = matrix[0].size();
    int row = matrix.size();
    //cout << row << " " << col <<  "  row col " << endl;
    vector<pair<int,int> >root;
    for(int i = 0;i<row;i++){
    	for(int j = 0;j<col;j++){
    		if(i == 0 || j == 0){
    			pair<int,int> px = make_pair(i,j);
    			root.push_back(px);
			}
		}
	}
		
	
	for(int i = 0;i<root.size();i++){
		int x = root[i].first;
		int y = root[i].second;
		//cout << x << " " << y << " :: "; 
		int m = matrix[x][y];
		while(x<row && y<col){
			//cout << x << " " << y  << " ";
			if(m!=matrix[x][y])return false;
			x++;y++;
		}
		//cout <<endl;
	}
	
	return true;
    
}


int main(){
	
	int row,col;
	cin >> row >> col;
	vector<vector<int> >matrix;
	for(int i = 0;i<row;i++){
		vector<int>v;
		for(int j = 0;j<col;j++){
			int x;cin >> x;
			v.push_back(x);
		}
		matrix.push_back(v);
	}
	cout << isToeplitzMatrix(matrix);
	return 0;
}
