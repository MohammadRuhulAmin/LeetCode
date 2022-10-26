class Solution {
public:
    int firstUniqChar(string s) {
        int length = s.length();
        bool checked[length];
        int ans = -1;
        memset(checked,false,sizeof(checked));
        for(int i = 0;i<length;i++){
            if(!checked[i]){
                char x = s[i];
                bool parentCheck = false;
                for(int j = 0;j<length;j++){
                    if(i!=j && !checked[j] && x == s[j]){
                        checked[j] = true;
                        parentCheck = true;
                    }
                }
                if(parentCheck)checked[i] = true;
            }
        }
        for(int i = 0;i<length;i++){
            if(!checked[i]){
                ans = i;
                break;
            }
        }
        return ans;

    }
};
