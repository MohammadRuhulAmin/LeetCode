class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
	set<vector<int>>ans;
	sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size();i++){
    	for(int j = i+1;j<nums.size();j++){
    		int left = j+1;
    		int right=nums.size()-1;
    		while(left<right){
    				 long long temp_sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);
    				if(temp_sum == target){
    					ans.insert({nums[i],nums[j],nums[left],nums[right]});
    					while(left<right && nums[left] == nums[left+1])left++;
    					while(left<right && nums[right] == nums[right-1])right--;
    					left++;right--;
					}
					else if(temp_sum>target)right--;
					else left++;
				}
		}
	}
	vector<vector<int>> result;
	for(auto&it:ans){
		result.push_back(it);
	}
    return result;
}
};