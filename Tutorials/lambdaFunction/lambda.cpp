#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> array = {1,2,3,4};
	auto compare = [](int a, int b){
		return a > b;
	};
	
	sort(array.begin(),array.end(),compare);
	for(auto x: array)cout << x << " ";
	vector<string> names = {"Ruhul" , "Sakib" , "Sajid","Nurul Islam"};
	sort(names.begin(),names.end(),[](string &a,string &b){
		return a>b;
	});
	for(auto x: names)cout << x << " ";
	
	return 0;
}
