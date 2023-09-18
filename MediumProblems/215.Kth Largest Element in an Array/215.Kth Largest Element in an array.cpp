class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>Q;
        for(const auto&ite:nums){
            Q.push(ite);
        }
        int ans = 0;
        while(k>0){
            ans = Q.top();
            Q.pop();
            k--;
        }
        return ans;
    }
};