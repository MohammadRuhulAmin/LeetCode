#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s){
	vector<pair<char,string> > vec;
	int length = s.length();
	string temp = "";
	s+= '\0';
	int index = 0;
	for(int i = 0;i<length;i++){
		if(s[i]== ' ' || s[i] == '\0'){
			vec.push_back(make_pair(pattern[index],temp));
			temp = "";
			index++;
		}
		else temp += s[i];
	}
	vec.push_back(make_pair(pattern[index],temp));
	for(int i = 0;i<vec.size();i++){
		char x = vec[i].first;
		string match = vec[i].second;
		for(int j = 0;j<vec.size();j++){
			if(match == vec[j].second)return false;
		}
	}
	
	for(int i = 0,j = vec.size()-1;i<=j;i++,j--)if(vec[i]!=vec[j])return false;
		
	return true;	
}
int main(){
	string pattern,s;
	getline(cin ,pattern);
	getline(cin , s);
	cout << wordPattern(pattern,s);
	
	return 0;
}
