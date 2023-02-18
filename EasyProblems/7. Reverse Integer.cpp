#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
	
	long n = 0;
	bool isNegNum = false;
	if(x<0)isNegNum = true;
	x = abs(x);
	while(x>0){
		int i = x%10;
		n*=10;
		n+=i;
		x/=10;
	}
	// checking if the number is in 32 bits range or not !
	if(n>INT_MAX || n <INT_MIN) return 0; 
	if(isNegNum)n*=-1;
	return n;
	
}
int main(){
	
	int n;
	cin >> n;
	cout << reverse(n);
	
	return 0;
}
