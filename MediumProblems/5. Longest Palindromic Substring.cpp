#include<bits/stdc++.h>
using namespace std;
int expandWindow(string s,int left,int right){
	while(left>=0 && right<s.length() && s[left] == s[right]){
		left--;
		right++;
	}
	return right-left-1;
}

string longestPalindrome(string s){
	int length = s.length();
	int startIndex = 0;
	int maxLen = 0;
	for(int i = 0;i<length;i++){
		int len1 = expandWindow(s,i,i);
		int len2 = expandWindow(s,i,i+1);
		int len = max(len1,len2);
		if(maxLen<len){
			maxLen = len;
			startIndex = i-(len-1)/2;
		}
	}
	return s.substr(startIndex,maxLen);
}


int main(){
	string s;
	cin >> s;
	cout << longestPalindrome(s);
	
	return 0;
}
