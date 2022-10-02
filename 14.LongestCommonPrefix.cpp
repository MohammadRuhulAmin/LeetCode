#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    vector<string> prefix;
    string ansString = "";
    int length = strs.size();
    for(int i = 0;i<length;i++){
    	string word = strs[i];
    	string temp = "";
    	for(int j = 0;j<word.length();j++){
    		temp +=word[j];
    		prefix.push_back(temp);
		}
	}
	int maxLen = 0;
    for(int i = 0;i<prefix.size();i++){
    	string prefix_word = prefix[i];
    	int count = 0;
    	for(int j = 0;j<prefix.size();j++){
    		if(prefix_word == prefix[j])count++;
		}
		if(count == length){
			if(prefix_word.length()>maxLen){
				maxLen = prefix_word.length();
				ansString = prefix_word;
			}
		}
	}
    return ansString;
}

int main(){
	int length;
	cin >> length;
	vector<string> strs;
	for(int i = 0;i<length;i++){
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	
	cout << longestCommonPrefix(strs);
	
	
	
	
	
	return 0;
}
