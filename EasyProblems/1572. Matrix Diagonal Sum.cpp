#include<bits/stdc++.h>
using namespace std;
int diagonalSum(vector<vector<int> >& mat) {
    int size = mat.size();
    int sum = 0;
    
  	for(int i = 0;i<size;i++){
  		sum += mat[i][i];	
	}
	for(int i = 0,j = size-1;i<size,j>=0;i++,j--){
		sum +=mat[i][j];
	}

	if(size%2 != 0) {
		int x = size/2;
		return sum-mat[x][x];
	}
    return sum;
}

// (0 |0)  (0 1)  (0 2)  (0 3) (0 4) (0 |5)
// (1 0)  (1 |1)  (1 2)  (1 3) (1 |4) (1 5)
// (2 0)  (2 1)  (2 |2)  (2 |3) (2 4) (2 5)
// (3 0)  (3 1)  (3 |2)  (3| 3) (3 4) (3 5)
// (4 0)  (4 |1)  (4 2)  (4 3) (4| 4) (4 5)
// (5 |0)  (5 1)  (5 2)  (5 3) (5 4) (5| 5)


int main(){
	
	vector<vector<int> >vec;
	int size;
	cin >> size;
	for(int i = 0;i<size;i++){
		vector<int>v1;
		for(int j = 0;j<size;j++){
			int x;cin >> x;
			v1.push_back(x);
		}
		vec.push_back(v1);
	}
	
	for(int i = 0;i<size;i++){
		for(int j = 0;j<size;j++){
			cout << vec[i][j] <<" ";
		}
		cout << endl;
	}
	
	cout << diagonalSum(vec);
	
	return 0;
}
