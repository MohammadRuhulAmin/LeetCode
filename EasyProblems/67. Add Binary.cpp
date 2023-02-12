#include<bits/stdc++.h>
using namespace std;


string addBinary(string a, string b){
	int aLen = a.length();
	int bLen = b.length();
	int zeros = aLen-bLen;
	string zeroString = "";
	for(int i = 0;i<abs(zeros);i++){
		zeroString+="0";
	}
	if(zeros>0)b = zeroString + b;
	else a = zeroString + a;
	string ans = "";
	int c = 0;
	int sum = 0;
	for(int i = a.length()-1;i>=0;i--){
		int x = a[i] - '0';
		int y = b[i] - '0';
		sum = x+y+c;
		if(sum == 3){
			c = 1;
			ans += "1";
		}
		else if(sum == 2){
			c = 1;
			ans += "0";
		}
		else if(sum == 1){
			c = 0;
			ans += "1";
		}
		else {
			c = 0;
			ans +="0";
		}
	}
	if(c == 1)ans += "1";
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	string a,b;
	cin >> a >> b;
	cout << addBinary(a,b);
	
	
	
	
	return 0;
}
