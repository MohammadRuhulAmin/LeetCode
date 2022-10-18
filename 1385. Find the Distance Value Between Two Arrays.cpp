class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        int cnt = 0;
        for(int i = 0;i<len1;i++){
            bool allMatched = true;
            for(int j = 0;j<len2;j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    allMatched = false;
                    break;
                }
            }
            if(allMatched)cnt++;
        }
        return cnt;
    }
};
