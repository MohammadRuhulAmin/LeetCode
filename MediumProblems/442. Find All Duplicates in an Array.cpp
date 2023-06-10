#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
	vector<int>ans;
	for(int i = 0;i<nums.size();i++){
		int index = nums[i];
		if(index<0)index = abs(index);
		if(nums[index]>0)nums[index] *=-1;
		else ans.push_back(index);
	}
	for(auto x:nums)cout << x << " ";
	cout << endl;
	return ans;
}
int main(){
	int length;
	vector<int>nums;
	cin >> length;
	for(int i = 0;i<length;i++){
		int x;cin >> x;
		nums.push_back(x);
	}
	vector<int> temp = findDuplicates(nums);
	for(auto x:temp){
		cout << x << " ";
	}
	return 0;
}
