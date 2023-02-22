#include<bits/stdc++.h>
using namespace std;
int findLUSlength(string a, string b) {
    int la = a.length();
    int lb = b.length();
    string ans = "";
    for(int i = 0;i<la;i++){
    	for(int j = i;j<la;j++){
    		string ta = a.substr(i,j-i+1);
    		for(int k = 0;k<lb;k++){
    			for(int l = k;l<lb;l++){
    				string tb = b.substr(k,l-k+1);
					if(ta.length() == tb.length() && ta!=tb){
						if(ans.length()<ta.length())ans = ta;	
					} 
				}
			}
		}
	}
	return (ans.length()== 0)? -1 : ans.length();
}
int main(){
	string a,b;
	cin >> a >> b; 
	cout << findLUSlength(a,b);
	
	return 0;
}
