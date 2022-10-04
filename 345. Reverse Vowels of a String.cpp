#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
 	int length = s.length();
 	string ans = "";
 	string vowel = "";
 	for(int i = 0;i<length;i++){
 		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
 			vowel+=s[i];
		}
	}
	int ln = vowel.length()-1;
	for(int i = 0;i<length;++i){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
 			ans += vowel[ln];
 			ln--;
		}
		else ans+=s[i];
	}
    return ans;
}

int main(){
	string str;
	cin >> str;
	cout << reverseVowels(str);
	
	
	
	return 0;
}
