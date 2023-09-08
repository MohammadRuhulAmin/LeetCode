class Solution {
public:
    void dfs(int n,int max_val,vector<bool>&visited,vector<int>&ans){
        if(n>max_val)return;
        else{
            visited[n] = true;
            ans.push_back(n);
            for(int i = 0;i<=9;i++){
                dfs(n*10 + i,max_val,visited,ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        vector<bool>visited(50005,false);
        for(int i = 1;i<=9;i++){
            if(!visited[i]){
                dfs(i,n,visited,ans);
            }
        }
        return ans;        
    }
};