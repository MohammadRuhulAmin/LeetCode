#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
	int carry = 0;
	digits[digits.size()-1]++;
	for(int i = digits.size()-1;i>=0;i--){
		digits[i]+=carry;
		int x = digits[i]%10;
		carry = 0;
		if(x == 0){
			digits[i] = 0;
			carry = 1;
		}
	}
	if(carry == 1)digits.insert(digits.begin(), carry);
	return digits;
}
int main(){
	vector<int>digits;
	int length;
	cin >> length;
	for(int i = 0;i<length;i++){
		int x;cin >> x;
		digits.push_back(x);
	}
	vector<int>ans = plusOne(digits);
	for(auto x:ans)cout << x <<  " ";
	
	return 0;
}

/*
1 2 3 4
1 2 3 5


9 
1 0

9 9 9
1 0 0 0



*/
