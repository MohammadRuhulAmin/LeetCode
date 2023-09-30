class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0]++;
        int count = 0;
        for(const auto&ite:nums){
            sum+= ite;
            count+= mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};