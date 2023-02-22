class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closeAns = 0;
        bool updated = false;
        for(int i = 0;i<nums.size();i++){
            int x = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = x+nums[left]+nums[right];
                if(!updated){
                    updated = true;
                    closeAns = sum;
                }
                if(abs(closeAns-target)>abs(sum-target))closeAns = sum;
                else if(sum-target<0)left++;
                else right--;
            }
        }
        return closeAns;
    }
};
