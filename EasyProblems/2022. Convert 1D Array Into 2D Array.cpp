class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int o_size = original.size();
        int m_size = m*n;
        vector<vector<int>>ans;
        if(o_size != m_size)return ans;
        else{
            int index = 0;
            for(int i = 0;i<m;i++){
                vector<int>temp;
                for(int j = 0;j<n;j++){
                    temp.push_back(original[index]);
                    index++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
