class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0;
        int tptr = 0;
        int slen = s.length();
        int tlen = t.length();
        bool checked[150];
        memset(checked,false,sizeof(checked));
        while(sptr<slen && tptr<tlen){
            if(s[sptr] == t[tptr]){
                checked[sptr] = true;
                sptr++;
                tptr++;
            }
            else tptr++;
        }
        for(int i = 0;i<slen;i++){
            if(!checked[i])return false;
        }
        return true;
    }
};
