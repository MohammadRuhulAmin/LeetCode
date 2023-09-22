#include<bits/stdc++.h>
using namespace std;
int findPairs(vector<int>& nums, int k) {
    int count  = 0;
    set<pair<int,int>>st;
	map<int,int>mp;
    for(const auto&ite:nums)mp[ite]++;
    for(const auto&ite:mp){
    	int item = ite.first;
    	int value = ite.second;
    	if(mp[item-k]!=0){
    		if(item == item-k && mp[item-k]>1)st.insert({item,item-k});
    		if(item>item-k)st.insert({item-k,item});
    		if(item<item-k)st.insert({item,item-k});
		}
	}
    

    
    return st.size();
}
int main(){
	int k;
	int range;cin >> k >> range ;
	vector<int>nums(range);
	for(int i = 0;i<range;i++){
		cin >> nums[i];
	}
	cout << findPairs(nums,k);
	
	return 0;
}