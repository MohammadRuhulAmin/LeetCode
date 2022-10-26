#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
	int length = s.length();
	stack<char>stk;
	bool ans = true;
	for(int i = 0;i<length;i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			stk.push(s[i]);
		}
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
			if(stk.empty()){
				ans = false;
				break;
			}
			char x = stk.top();
			if( x == '(' && s[i] != ')'){
				ans = false;
				break;
			}
			else if(x == '[' && s[i]!=']'){
				ans = false;
				break;
			}
			else if(x == '{' && s[i]!='}'){
				ans = false;
				break;
			}
			else stk.pop();
		}
	}
    if(!stk.empty())ans = false;
	return ans;    
}
int main(){
	
	string str;
	cin >> str;
	cout << isValid(str);
	
	
	
	return 0;
}


/*
()()()


*/
