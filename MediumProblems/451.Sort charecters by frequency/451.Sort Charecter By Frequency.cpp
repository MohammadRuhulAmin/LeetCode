#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
	string ans = "";
	map<char,int>mp;
	for(int i = 0;i<s.length();i++){
		if(mp.find(s[i])!=mp.end())mp[s[i]]++;
		else mp[s[i]] = 1;
	}
	vector<pair<char,int>>vec(mp.begin(),mp.end());
	std::sort(vec.begin(), vec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second > b.second;  // Sort in descending order by frequency
    });
	for(auto&ite:vec){
		while(ite.second>0){
			ans+=ite.first;
			ite.second--;
		}
	}
	
	return ans;
}

int main(){
	string str;
	cin >> str;
	cout << frequencySort(str);
	
	
	return 0;
}