#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int length = s.length();
    string ans = "";
    int start = 0;
    for(int i = 0;i<length;i++){
    	if(s[i] == ' '){
    		for(int j = i-1;j>=start;j--){
    			ans+=s[j];
			}
			ans+=' ';
			start = i+1;
		}
		if(i == length-1){
			for(int j = i;j>=start;j--){
    			ans+=s[j];
			}
		}
		//ruhul is a good boy
		
	}
	
    return ans;
}


int main(){
	string str;
	//cin >> str;
	getline(cin,str);
	cout << reverseWords(str);

	
	
	return 0;
}
