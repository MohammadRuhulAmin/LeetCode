class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int f = 1;
        for(int i = 0;i<=n;i++){
            int count = 0;
            int temp = i;
            while(temp>0){
                int x = temp&f;
                if(x)count++;
                temp = temp >> 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
