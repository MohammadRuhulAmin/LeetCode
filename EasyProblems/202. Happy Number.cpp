#include<bits/stdc++.h>
using namespace std;

int isHappy(int n){
	set <int> node;
	int sum = 0;

	while(n>0){
		int x = n%10;
		cout << x << " ";
		sum += (x*x);
		n/=10;
	}
	cout << sum << endl;
	return sum;
}


int main(){
	int n;
	cin >> n;
	cout << " x " + isHappy(n);
	
	
	return 0;
}
