#include<bits/stdc++.h>
using namespace std;
vector<string>topKFrequent(vector<string>&words,int k){
	vector<string>ans;
	unordered_map<string,int>mp;
	for(const auto&ite:words)mp[ite]++;
	const auto comp = [&mp](pair<string,int>&a,pair<string,int>&b){
		return(mp[a.first] == mp[b.first])? (a.first>b.first): (mp[a.first]<mp[b.first]);
	};
	priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(comp)>maxHeap(comp);
	for(const auto&ite:mp){
		maxHeap.push({ite.first,ite.second});
	}
	while(k>0){
		ans.push_back(maxHeap.top().first );
		k--;
		maxHeap.pop();
	}
	return ans;
}

int main(){
	vector<string>words;
	int range,k;
	cin >> k >> range;
	for(int i = 0;i<range;i++){
		string str;cin >> str;
		words.push_back(str);
	}
	vector<string>ans = topKFrequent(words,k);
	
	return 0;
}

//3 6
//love i abc i abc xx xx