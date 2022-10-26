class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int size = matrix.size();
        bool ans = true;
        for(int i = 0;i<size;i++){
            set<int>elem;
            for(int j = 0;j<size;j++){
                elem.insert(matrix[i][j]);
            }
            if(elem.size() != size)return false;
        }
        for(int i = 0;i<size;i++){
            set<int>elem;
            for(int j = 0;j<size;j++){
                elem.insert(matrix[j][i]);
            }
            if(elem.size()!=size)return false;
        }

        return true;
    }
};
