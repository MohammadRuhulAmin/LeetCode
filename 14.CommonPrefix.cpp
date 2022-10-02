#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 1)return strs[0];
	string LCP = strs[0];
	int count = 0;
	int lpcLength = LCP.length();
	string ans = "";
	int length = strs.size();
	for(int i = 1;i<length;i++){
		count = 0;
		bool foundPrefix = false;
		string tempString = strs[i];
		for(int j = 0;j<tempString.length();j++){
			if(LCP[j]!=tempString[j])break;
			else {
				foundPrefix = true;
				count++;
			}
		}
		if(!foundPrefix)lpcLength = 0;
		else if(count<lpcLength)lpcLength = count;
	}
	for(int i = 0;i<lpcLength;i++)ans+= LCP[i];
	return ans;
}


int main(){
	
	vector<string> strs;
	int len;
	cin >> len;
	for(int i = 0;i<len;i++){
		string str;
		cin >> str;
		strs.push_back(str);
	}
	cout << longestCommonPrefix(strs);
	
	return 0;
}

/*


class Solution {
public:

string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 1)return strs[0];
	string LCP = strs[0];
	int count = 0;
	int lpcLength = LCP.length();
	string ans = "";
	int length = strs.size();
	for(int i = 1;i<length;i++){
		count = 0;
		bool foundPrefix = false;
		string tempString = strs[i];
		for(int j = 0;j<tempString.length();j++){
			if(LCP[j]!=tempString[j])break;
			else {
				foundPrefix = true;
				count++;
			}
		}
		if(!foundPrefix)lpcLength = 0;
		else if(count<lpcLength)lpcLength = count;
	}
	for(int i = 0;i<lpcLength;i++)ans+= LCP[i];
	return ans;
}

};










*/
