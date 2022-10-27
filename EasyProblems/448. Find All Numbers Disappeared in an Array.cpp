class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int>mn;
        vector<int>ans;
        int ln = nums.size();
        for(int i = 0;i<ln;i++){
            mn.insert(nums[i]);
        }
        for(int i = 0;i<ln;i++){
            int c = i+1;
            auto it = mn.find(c);
            if(it == mn.end())ans.push_back(c);

        }
        return ans;
    }
};
