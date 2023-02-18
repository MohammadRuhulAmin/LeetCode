#include<bits/stdc++.h>
using namespace std;


bool divisorGame(int n) {
	string turn = "Alice";
	for(int i = n;i>0;i--){
		int x = i;
		if(x%2 == 0){
			n-=x;
			if(turn == "Alice")turn = "Bob";
			else turn = "Alice";
		}
		else break;
	}
	if(turn == "Alice")return 0;
	return 1;
}

int main(){
	int n;
	cin >> n;
	cout << divisorGame(n);
	
	return 0;
}
