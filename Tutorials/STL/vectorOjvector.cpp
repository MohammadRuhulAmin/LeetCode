#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;cin >> N;
	vector<int>v[N];
	for(int i = 0;i<N;i++){
		int n;
		cin >> n;
		for(int j = 0;j<n;j++){
			int x;cin >> x;
			v[i].push_back(x);
		}
	}
	
	for(int i = 0;i<N;i++){
		int s = v[i].size();
		for(int j = 0;j<s;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
	return 0;
}
