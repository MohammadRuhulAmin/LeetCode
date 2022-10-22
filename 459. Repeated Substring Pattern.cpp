#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
	int length = s.length();
	if(length == 1)return false;
	string subStr = "";
	string fString = "";
	bool foundPattern = false;
	for(int i = 0;i<length;i++){
		subStr+= s[i];
		fString = "";
		int sblength = subStr.length();
		int repeat = length/sblength;
		for(int j = 0;j<repeat;j++){
			fString += subStr;
		}
		if(fString == s && subStr !=s){
			foundPattern = true;
		}
	}
	return foundPattern;        
}


int main()
{
 	string s;
 	cin >> s;
 	cout << repeatedSubstringPattern(s);
    return 0;
}

/*
	ababab
	ab
	


*/
