#include<bits/stdc++.h>
using namespace std;
int balancedStringSplit(string s) {
    int size = s.length();
    string sR = "";
    string sL = "";
    int count = 0;
    for(int i = 0;i<size;i++){
    	if(s[i] == 'R')sR +=s[i];
    	if(s[i] == 'L')sL +=s[i];
    	if(sR.length() == sL.length()){
    		cout << sR << " " << sL << endl;
			count++;
    		sR = "";
    		sL = "";
		}
	}
	cout << endl;
	return count;
    
}

int main(){
	string str;
	cin >> str;
	cout << balancedStringSplit(str);
	
	
	return 0;
}
