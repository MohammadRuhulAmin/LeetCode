#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<int,pair<int,int>>cont;
	int len = nums.size();
	for(int i = 0;i<len;i++){
		for(int j = i+1;j<len;j++){
			
		}
		for(int j = 0;j<i;j++){
			cont[nums[i]+nums[j]] = {i,j};
		}
	}
}
int main(){
	
	int range,target;cin >> range >> target;
	vector<int>nums;
	for(int i = 0;i<range;i++){
		int x;cin >> x;
		nums.push_back(x);
	}
	auto result = fourSum(nums,target);
	for(auto &x:result){
		for(auto &y:x){
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}
