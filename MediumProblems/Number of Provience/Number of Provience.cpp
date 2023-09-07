class Solution {
public:
    void traverse(int node,vector<vector<int>>&isConnected,vector<bool> &flag){
        flag[node] = true;
        for(int i = 0;i<isConnected.size();i++){
            if(isConnected[node][i] == 1 && !flag[i]){
                traverse(i,isConnected,flag);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<bool>flag(isConnected.size(),false);
        for(int i = 0;i<isConnected.size();i++){
            if(!flag[i]){
                traverse(i,isConnected,flag);
                ans++;
            }
        }
        return ans;
    }
};
