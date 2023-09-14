#include<bits/stdc++.h>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
	vector<string>ans;
	if(s.length()<10)return ans;
	map<string,int>table;
	for(int i = 0;i<s.length()-9;i++){
		int j = i;
		string tempStr = "";
		while(j-i<10){
			tempStr += s[j];
			j++;
		}
		cout << tempStr << endl;
		if(table.find(tempStr) == table.end())table[tempStr] = 1;
		else table[tempStr]++;
	}
	for(const auto &ite:table){
		if(ite.second>1)ans.push_back(ite.first);
		
	}
	return ans;
}
int main(){
	string str;
	cin >> str;
	vector<string> temp = findRepeatedDnaSequences(str);
	cout << endl;
	for(const auto&ite:temp){
		cout << ite << endl;
	}
	
	return 0;
}