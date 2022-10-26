   #include<bits/stdc++.h>
   using namespace std;
   
   
   bool isPalindrome(string s) {
        string str = "";
        int length = s.length();
        for(int i = 0;i<length;i++){
        	if(s[i] == 32)continue;
            else if(s[i]>=65 && s[i]<=90)str += tolower(s[i]);
            else if(s[i]>=48 && s[i]<=57)str += tolower(s[i]);
            else if(s[i]>=97 && s[i]<=122)str += tolower(s[i]);
        }
        cout << str;
        int newLen = str.length();
        for(int i = 0,j = newLen-1;i<=j;i++,j--){
            if(str[i]!=str[j])return false;
        }
        return true;
    }
   
   int main(){
   	
   	string s;
   	getline(cin,s);
   	cout << isPalindrome(s);
   	
   	return 0;
   } 
