#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<vector<int> > ans;
	for(int i = 0;i<nums.size();i++){
		int left = i+1;
		int right = nums.size()-1;
		int x = nums[i];
		while(left<right){
			if(nums[left]+nums[right] + x == 0 ){
				ans.push_back({x,nums[left],nums[right]});
				while(left<right && nums[left] == nums[left+1])left++;
				while(left<right && nums[right] == nums[right-1])right--;
				left++;right--;
			}
			else if(nums[left]+nums[right]+x > 0)right--;
			else left++;
		}
	}
	sort(ans.begin(),ans.end());
	auto last = unique(ans.begin(),ans.end());
	ans.erase(last,ans.end());
	
	return ans;
}
int main(){
	int range;cin >> range;
	vector<int> nums;
	for(int i = 0; i < range ;i++){
		int x;scanf("%d",&x);
		nums.push_back(x);
	}
	
	vector<vector<int> > ans = threeSum(nums);
	cout << ans.size() << endl;
	for(int i = 0;i<ans.size();i++){
		for(int j = 0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
