class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElem = nums[0];
        int count = 1;
        int length = nums.size();
        for(int i = 1;i<length;i++){
            if(majorElem != nums[i]){
                if(count-1>0){
                    count--;
                }
                else if(count-1 == 0){
                    majorElem = nums[i];
                }
            }
            else count++;
        }
        return majorElem;
    }
};
