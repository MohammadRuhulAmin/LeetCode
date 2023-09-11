class Solution {
public:
    vector<int> splitDigits(int n,vector<int>&nums){
	if(n == 0){
		reverse(nums.begin(),nums.end());
		return nums;
	}
	nums.push_back(n%10);
	return splitDigits(n/10,nums);
}

int toNumber(vector<int>nums,int n){
	string num = "";
	for(int i = 0;i<nums.size();i++){
		 num += nums[i]+'0';
	}
	const long ans = stol(num);
	return (ans>INT_MAX || ans<n)?-1:ans; 
}

int nextGreaterElement(int n){
	vector<int>nums;
	int peakIndex = -1;
	vector<int> vec = splitDigits(n,nums);
	bool decreasing = true;
	for(int i = nums.size()-1;i>0;i--){
		if(nums[i]>nums[i-1]){
			decreasing = false;
			peakIndex = i;
			break;
		}
	}
	if(decreasing)return -1;
	else{
		int prev_peakIndex = peakIndex-1;
		int second_highest_peak = peakIndex;
		for(int i = peakIndex;i<nums.size();i++){
			if(nums[i]>nums[prev_peakIndex] && nums[i]<=nums[peakIndex]){
				second_highest_peak = i;
			}
		}
		swap(nums[prev_peakIndex],nums[second_highest_peak]);
		reverse(nums.begin()+peakIndex,nums.end());
		 return toNumber(nums,n);
		 
	}

}

};