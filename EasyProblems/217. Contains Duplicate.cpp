class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i = 0;i<size;i++){
            int elem = nums[i];
            int high = size-1;
            int low = 0;
            int mid = 0;
            while(low<=high){
                int mid = (high+low)/2;
                if(nums[mid] == elem && i!=mid)return true;
                else if(nums[mid]>elem)high = mid-1;
                else low = mid+1;
            }
        }
        return false;
        
    }
};
