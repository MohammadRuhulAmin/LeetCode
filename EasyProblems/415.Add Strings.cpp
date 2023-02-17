#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    string addZero = "";
    string ans = "";
    int x = abs(len1-len2);
    for(int i = 0;i<x;i++)addZero += '0';
    if(len1>len2)num2  = addZero + num2;
	else num1 = addZero + num1;
	int nLen = num1.length();
	int c = 0;
	for(int i = nLen-1;i>=0;i--){
		int sum = (num1[i]-'0') + (num2[i]-'0') + c;
		c = sum/10;
		ans+= (sum%10) + '0';
	}
	if(c!=0)ans += c +'0';
	reverse(ans.begin(),ans.end());
	return ans;
    
}

int main(){
	
	string num1,num2;
	cin >> num1 >> num2;
	cout << addStrings(num1,num2);	
	
	return 0;
}
