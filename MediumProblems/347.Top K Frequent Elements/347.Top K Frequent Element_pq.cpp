class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++)mp[nums[i]]++;
        auto compare = [](const auto&a,const auto&b){return a.second <b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)>maxHeap(compare);
        for(const auto&ite:mp){
            maxHeap.push({ite.first,ite.second});
        }
        
        while(k>0){
            auto tp = maxHeap.top();
            ans.push_back(tp.first);
            maxHeap.pop();
            k--;
        }
    return ans;
    }
};

