#include<bits/stdc++.h>
using namespace std;


int main(){
	vector<int> v = {1,2,3,4};
	vector<int> :: iterator it;
	for(it = v.begin();it!=v.end();++it){
		cout << *it << " ";
	}
	
	cout << endl;
	cout << " Begin Element :  " << *v.begin();
	cout << " After End Element : " << *v.end();
	
	// it++ sends next iterator 
	// it+1 sends next location
	
	vector<pair<int,int> > vp = {{1,2},{2,3},{3,4}};
	
	return 0;
}
