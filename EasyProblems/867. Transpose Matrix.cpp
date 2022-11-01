#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> >&matrix){
	cout << endl;
	int row = matrix.size();
	int col = matrix[0].size();
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int> > transpose(vector<vector<int> >& matrix) {
          int row = matrix.size();
          int col = matrix[0].size();
          int nRow = col;
          int nCol = row;
          vector<vector<int> > trans(nRow,vector<int>(nCol));
          for(int i = 0;i<row;i++){
              for(int j = 0;j<col;j++){
                  trans[j][i] = matrix[i][j]; 
              }
          }
          return trans;
}
 


int main(){
	vector<vector<int> > matrix;
	int m,n;
	cin >> m >> n;
	for(int i = 0;i<m;i++){
		vector<int> v;
		for(int j = 0;j<n;j++){
			int x;cin >> x;
			v.push_back(x);
		}
		matrix.push_back(v);
	}
	
	vector<vector<int> > trans =  transpose(matrix);
	print(trans);
	
	return 0;
}
