#include<bits/stdc++.h>
using namespace std;
string longestNiceSubstring(string s) {
	int len = s.length();
	string ans = "";
	for(int i = 0;i<len;i++){
		for(int j = i;j<len;j++){
			string tempStr = s.substr(i,j-i+1);
			unordered_set<char> m_set(tempStr.begin(),tempStr.end());
			bool flag = true;
			for(char x:m_set){
				if(m_set.find(toupper(x)) != m_set.end()  &&  m_set.find(tolower(x)) != m_set.end())continue;
				else {
					flag = false;break;
				}
			}
			if(flag && ans.length()<tempStr.length())ans = tempStr;
		}
	}        
	return ans;
}
int main(){
	string s;
	cin >> s;
	cout << longestNiceSubstring(s);
	
	
	return 0;
}
