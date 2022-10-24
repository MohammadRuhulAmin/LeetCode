    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        int mid;
        int insertOf = 0;
        while(low<=high){
            mid = (high+low)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid]>target)high = mid-1;
            else {
                low = mid+1;
                insertOf = low;
            }
        }
        return insertOf;
    }
