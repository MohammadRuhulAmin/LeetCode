#include<bits/stdc++.h>
using namespace std;

int main(){
	int length;
	cin >> length;
	char str[length];
	for(int i = 0;i<length;i++)cin >> str[i];
	
	for(int i = 0;i<length;i++)cout << str[i] << " ";
	
	int start = 0;
	int end = length-1;

	while(start<end){
		bool sp = false;
		bool lp = false;
		if(str[start] == 'a' || str[start] == 'e' || str[start] == 'i' || str[start] == 'o' || str[start] == 'u'){
			sp = true;	
		}
		if(str[end] == 'a' || str[end] == 'e' || str[end] == 'i' || str[end] == 'o' || str[end] == 'u'){
			lp = true;
		}
		if(sp && lp){
			char x = str[start];
			str[start] = str[end];
			str[end] = x;
			start++;end--;
		}
		else if(sp && !lp ){
			end--;
		}
		else start++;
	}
	cout << endl;	
	for(int i = 0;i<length;i++)cout << str[i] << " ";
	
	
	return 0;
}
