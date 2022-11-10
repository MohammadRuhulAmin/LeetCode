#include<bits/stdc++.h>
using namespace std;

// vector<int> luckyNumbers (vector<vector<int> >& matrix){
//	vector<int> ans;
//	int row = matrix.size();
//	int col = matrix[0].size();
//	for(int i = 0;i<row;i++){
//		for(int j = 0;j<col;j++){
//			int elem = matrix[i][j];
//			int c_row = i;
//			int c_col = j;
//			cout << elem << " : \n" ;
//			cout << "Search By Row : \n";
//			for(int k = 0;k<col;k++){
//				cout <<"(" <<  c_row << " " << k << ")";
//			}
//			cout << endl;
//			cout << "Search By Col : \n";
//			for(int k = 0;k<row;k++){
//				cout <<"(" <<  k << " " << c_col << ")";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	
//	}
//	return ans;
//}

vector<int> luckyNumbers (vector<vector<int> >& matrix){
	vector<int> ans;
	int row = matrix.size();
	int col = matrix[0].size();
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			int elem = matrix[i][j];
			int c_row = i;
			int c_col = j;
			bool rRule = true;
			bool cRule = true;
			for(int k = 0;k<col;k++){
				if(matrix[c_row][k]<elem){
					rRule = false;
					break;
				}
			}
			
			for(int k = 0;k<row;k++){
				if(matrix[k][c_col]>elem){
					cRule = false;
					break;
				}
			}
			if(rRule && cRule)ans.push_back(elem);
		}
	}
	return ans;
}


int main(){
	
	vector<vector<int> > matrix;
	int row,col;
	cin >> row >> col;
	for(int i = 0;i<row;i++){
		vector<int> v;
		for(int j = 0;j<col;j++){
			int x;cin >> x;
			v.push_back(x);
		}
		matrix.push_back(v);
	}
	
	vector<int> sln = luckyNumbers(matrix);
	vector<int> :: iterator ite;
	for(ite = sln.begin();ite!=sln.end();ite++){
		cout << *ite << " ";
	}
	return 0;
}
