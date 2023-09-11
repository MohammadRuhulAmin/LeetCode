#include<bits/stdc++.h>
using namespace std;
int containsNearbyDuplicate(vector<int>&nums, int k) {
	 map<int,int>num_order;
	 for(int i = 0;i<nums.size();i++){
	 	map<int,int>::iterator ite = num_order.find(nums[i]);
	 	if(ite == num_order.end())num_order[nums[i]] = i;
	 	else{
	 		int index = ite->second;
			int value = ite->first;
			if(abs(index-i) <= k && i!=index)return true;
			else{
				num_order.erase(value);
				num_order[nums[i]] = i;
			}
		}
	 }
    return 0;
}
int main(){
	int k;cin >> k;
	vector<int>nums;
	int range;
	cin >> range;
	for(int i = 0;i<range;i++){
		int x;cin >> x;
		nums.push_back(x);
	}
	
	cout << containsNearbyDuplicate(nums,k);
	
	return 0;
}