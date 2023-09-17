class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())mp[nums[i]]++;
            else mp[nums[i]] = 1;
        }
        vector<pair<int,int>>vec (mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](const pair<int,int>&a,const  pair<int,int>&b){
    	return a.second > b.second;
	});
    auto ite = vec.begin();
        while(k>0){
            ans.push_back(ite->first);
            ite++;
            k--;
        }
    return ans;
    }
};

