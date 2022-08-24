class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int>ansIndex;
        bool foundSln = false;
        for(int i = 0;i<length;i++){
            for(int j = 0;j<length;j++){
                if(i!=j){
                    if(nums[i]+nums[j] == target){
                        ansIndex.push_back(i);
                        ansIndex.push_back(j);
                        foundSln = true;
                        break;
                    }
                }
            }
            if(foundSln)break;
        }
        return ansIndex;
        
    }
};
