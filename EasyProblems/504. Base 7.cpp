#include<bits/stdc++.h>
using namespace std;
string convertToBase7(int num){
	string ans = "";
	while(num>0){
		int x =  num%7 ;
		ans += x+'0';
		num/=7;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int num;
	cin >> num;
	cout << convertToBase7(num);
	return 0;
}
