class Solution {
public:
   void nextPermutation(vector<int>& nums) {
    int highest_peak = -1;
    int length = nums.size();
    for(int i = length-1;i>0;i--){
    	if(nums[i]>nums[i-1]){
    		highest_peak = i;
    		break;
		}
	}
	if(highest_peak == -1){
		sort(nums.begin(),nums.end());
		
	}
	else{
		int prev_highest_peak = highest_peak-1;
		int swap_index = highest_peak;
		for(int i = highest_peak+1;i<length;i++){
			if(nums[i]>nums[prev_highest_peak] && nums[i]<=nums[swap_index]){
				swap_index = i;
			}
		}
		swap(nums[prev_highest_peak],nums[swap_index]);
		reverse(nums.begin()+highest_peak,nums.end());
	}
	   
            
}
};