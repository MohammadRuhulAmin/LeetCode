class Solution {
public:
    int singleNumber(vector<int>& nums){
        int size = nums.size();
        int ans = nums[0];
        for(int i = 1;i<size;i++){
            ans ^=nums[i];
        }
        return ans;
       
    }
};
