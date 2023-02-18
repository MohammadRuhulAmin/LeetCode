#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
	if(x > 2147483641)return 0;
	// 2147483647
	int n = 0;
	bool isNegNum = false;
	if(x<0)isNegNum = true;
	x = abs(x);
	while(x>0){
		int i = x%10;
		n*=10;
		n+=i;
		x/=10;
	}
	if(isNegNum)n*=-1;
	return n;
	
}
int main(){
	
	int n;
	cin >> n;
	cout << reverse(n);
	
	return 0;
}
