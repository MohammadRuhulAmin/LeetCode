#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack,string needle){
	int nlen = needle.length();
	int hlen = haystack.length();
	if(nlen>hlen)return -1;
	bool firstIndex = false;
	for(int i = 0;i<=hlen-nlen;i++){
		string temp = "";
		int l = 0;
		for(int j=i;;j++){
			if(l == nlen)break;
			temp += haystack[j];
			l++;
		}
//		cout << temp << " " << endl;
		if(temp == needle && !firstIndex)return i;
	}
	return -1;
}
int main(){
	string haystack,needle;
	cin >> haystack >> needle;
	cout << strStr(haystack,needle);
	

	
	
	
	return 0;
}
