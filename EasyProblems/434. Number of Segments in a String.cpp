   #include<bits/stdc++.h>
   using namespace std;
   
   
   int countSegments(string s) {
        int segment = 0;
        int length = s.length();
        string temp = "";
		for(int i = 0;i<length;i++){
        	if(s[i] != ' ')temp+=s[i];
			else{
				if(temp.length()>0)segment++;
				temp = "";
			}			
		}
		if(temp.length()>0)segment++;
        
        
        return segment;
    }
    
int main(){
	string s;
	getline(cin,s);
	cout << countSegments(s);
	
	return 0;
}
