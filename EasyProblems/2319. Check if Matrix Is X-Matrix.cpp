#include<bits/stdc++.h>
using namespace std;
bool checkXMatrix(vector<vector<int> >& grid) {
        int size = grid.size();
        bool ld = true,rd = true,nz = true;
        for(int i = 0;i<size;i++){
            for(int j = 0;j<size;j++){
                if(i == j && grid[i][j] ==0){
                    ld = false;
                    break;
                }
                if(i+j == size-1 && grid[i][j] == 0){
                    rd= false;
                    break;
                }
                if(i!=j && i+j!=size-1 && grid[i][j] != 0){
                    nz = false;
                    break;
                }
            }
            if(!ld || !rd || !nz)break;
        }
        if(ld && rd && nz)return true;
        return false;
}


int main(){
	vector<vector<int> >mat;
	int s;
	cin >> s;
	for(int i = 0;i<s;i++){
		vector<int> v;
		for(int j = 0;j<s;j++){
			int x;cin >> x;
			v.push_back(x);
		}
		mat.push_back(v);
	}
	
	cout << endl;
	
	for(int i = 0;i<s;i++){
		for(int j = 0;j<s;j++){
			cout << mat[i][j] <<" ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << checkXMatrix(mat);
	
	return 0;
}
