#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
	int short_window = INT_MAX;
	int sum = 0;
	int right = 0;
	int left = 0;
	while(right<nums.size()){
		sum += nums[right];
		if(sum>=target){
			while(sum>=target){
				sum -= nums[left];
				left++;
			}
			short_window = min(short_window,right-left+2);
		}
		right++;
	}
	
	return short_window == INT_MAX?0:short_window;
}

int main(){
	int target;
	vector<int>nums;
	int range;
	cin >> target >> range;
	for(int i = 0;i<range;i++){
		int x;cin >> x;
		nums.push_back(x);
	}
	cout << minSubArrayLen(target,nums);
	return 0;
}