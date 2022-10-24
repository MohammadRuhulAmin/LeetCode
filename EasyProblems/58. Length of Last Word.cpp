#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
 	int length =  s.length();
 	int index = length-1;
 	int count = 0;
 	if(s[index] != ' '){
 		for(int i = index;;i--){
			if(s[i] == ' ' && i>0){
				return count;
			}
			else if(i == 0 && s[i]!= ' '){
				return count+1;
			}
			else if(i == 0 && s[i] == ' ')return count;
			else count++;
				
		}	
	}
	else{
		while(s[index] == ' ')index--;
		for(int i = index;;i--){
			if(s[i] == ' ' && i>0){
				return count;
			}
			else if(i == 0 && s[i]!= ' '){
				return count+1;
			}
			else if(i == 0 && s[i] == ' ')return count;
			else count++;
				
		}	
	}
 	
 	
 	
	return count;
 
 
}

/*
	case :1 
		"Ruhul Amin"
	case :2 
		"Ruhul Amin  "
	case 3: 
		"Ruhul"
	
*/


int main(){
	
	string str;
	getline(cin,str);
	cout << lengthOfLastWord(str); 	
	
	return 0;
}
