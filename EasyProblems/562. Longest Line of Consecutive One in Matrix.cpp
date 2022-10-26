class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int length = nums.size();
        int sum = 0;
        for(int i = length-1;i>=0;i--){
            if(i%2 == 0)sum+=nums[i];
        }
        return sum;
    }
};

/*
    6 , 2 , 6 , 5 , 1 , 2 
    => 6,6
    => 5,2
    => 1,2
    --------
    6+ 2+ 1 = 9

    1,2, 2,5, 6,6
    

    1,4,3,2
    =>4,3
    =>2,1

    
    

    

*/
