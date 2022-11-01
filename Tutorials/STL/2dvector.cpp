#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int> > v;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n ;i++){
		vector<int>x;
		for(int j = 0;j<m;j++){
			int l ;cin >> l;
			x.push_back(l);
		}
		v.push_back(x);
	}
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
	
	return 0;
}
