#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

bool checkXMatrix(vector<vector<int>>& grid) {
    
    bool leftDiagonal = true;
    bool rightDiagonal = true;
    bool zeroTerm = true;
    for(int i = 0;i<grid.size();i++){
    	for(int j = 0;j<grid.size();j++){
    		if(i == j){
    			if(grid[i][j] == 0){
    				leftDiagonal = false;
    				break;
				}
			}
			if(i+j == grid.size()-1){
				if(grid[j][j] == 0){
					rightDiagonal = false;
					break;
				}
			}
			if(i!=j && i+j!=grid.size()-1){
				if(grid[i][j] !=0){
					zeroTerm = false;
					break;
				}
			}
		}
		if(!leftDiagonal || !rightDiagonal || !zeroTerm)break;
	}
	
   
	
	if(leftDiagonal && rightDiagonal && zeroTerm)return true;
	return false;   
}

int main(){
	
	int size;
	vector<vector<int> > grid;
	cin >> size;
	for(int i = 0;i<size;i++){
		vector<int> v;
		for(int j = 0;j<size;j++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		grid.push_back(v);
	}
	cout << endl;
	for(int i = 0;i<size;i++){
		for(int j = 0;j<size;j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << checkXMatrix(grid);
=======
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
	
>>>>>>> b99455ea62056367ceb166a39cf2d72c7a153245
	return 0;
}
