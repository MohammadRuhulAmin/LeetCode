class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(const auto&item:nums)mp[item]++;
        for(const auto&item:mp){
            if(item.second == 1){
                int prev = item.first-1;
                int next = item.first+1;
                if(mp.find(prev) == mp.end() && mp.find(next) == mp.end())
                ans.push_back(item.first);
            }
            else continue;
            
        }
        return ans;
    }
};