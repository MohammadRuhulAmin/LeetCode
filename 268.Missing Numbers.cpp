class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int next = 0;
       bool foundMissing = false;
       int len = nums.size();
       sort(nums.begin(),nums.end());
       for(int i = 0;i<len;i++){
           if(nums[i] == next){
               next++;
           }
           else if(nums[i]!=next){
               foundMissing = true;
               return next;
           }
       }
        return nums[len-1]+1;
    }
};
