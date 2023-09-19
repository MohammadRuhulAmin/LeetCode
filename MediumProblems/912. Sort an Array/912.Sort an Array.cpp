class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans;
        auto comp = [](int &a,int &b){
            return a>b;
        };
        priority_queue<int,vector<int>,decltype(comp)>heap(comp);
        for(const auto&ite:nums){
            heap.push(ite);
        }
        while(!heap.empty()){
            int elem = heap.top();
            ans.push_back(elem);
            heap.pop();
        }
        return ans;
    }
};