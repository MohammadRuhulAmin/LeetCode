class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int len = nums.size();
       if(len == 1 || len == 0)return ;
       int right = 0;
       int left = 0;
       while(right<len){
           if(nums[right] == 0)++right;
           else {
               int temp = nums[right];
               nums[right] = nums[left];
               nums[left] = temp;
               ++left;
               ++right;
           }
          
       }
    }
};
