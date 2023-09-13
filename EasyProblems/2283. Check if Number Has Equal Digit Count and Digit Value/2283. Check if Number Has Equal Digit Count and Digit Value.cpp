#include<bits/stdc++.h>
using namespace std;

bool digitCount(string num){
	map<int,int> hashMap;
	for(int i = 0;i<num.size();i++){
		hashMap[i] = 0;
	}
	for(int i =0;i<num.size();i++){
		int temp = num[i] - '0';
		hashMap[temp]++;
	}
	string temp_ans = "";
	for(const auto&ite:hashMap)temp_ans += ite.second +'0';
	cout << temp_ans;
	if(temp_ans == num)return true;
	return false;
}

int main(){
	string str;
	cin >> str;
	cout << digitCount(str);
	return 0;
}