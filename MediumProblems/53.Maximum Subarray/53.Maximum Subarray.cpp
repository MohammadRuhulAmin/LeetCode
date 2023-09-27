class Solution {
public:
    int maximumCrossingSum(vector<int>&nums,int low,int mid,int high){
        int sum = 0;
        int leftSum = INT_MIN;
        int rightSum = INT_MIN;
        for(int i = mid;i>=low;i--){
            sum += nums[i];
            if(sum>leftSum)leftSum = sum;
        }
        sum = 0;
        for(int i = mid;i<=high;i++){
            sum+=nums[i];
            if(sum>rightSum)rightSum = sum;
        }
        return max(max(leftSum,rightSum),leftSum+rightSum-nums[mid]);
    }
    int maximumSubArraySum(vector<int>&nums,int low,int high){
        if(low>=high)return nums[low];
        int mid = low+(high-low)/2;
        int leftSum  = maximumSubArraySum(nums,low,mid);
        int rightSum = maximumSubArraySum(nums,mid+1,high);
        int ans = max(leftSum,rightSum);
        ans = max(ans,maximumCrossingSum(nums,low,mid,high));
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return maximumSubArraySum(nums,0,nums.size()-1);
    }
};
